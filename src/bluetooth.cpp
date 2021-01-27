#include <bluetooth.h>
#include <QPushButton>

Bluetooth::Bluetooth(QListWidget *listWidget)
{
    m_listWidget = listWidget;
    //create device
    localDevice = new QBluetoothLocalDevice;
    agent = new QBluetoothDeviceDiscoveryAgent(this);
    addressList = new QList<QBluetoothAddress>; //create address list;
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    checkDeviceBluetooth();

    //create discovery agent and connect to it's signals
    connect(agent,&QBluetoothDeviceDiscoveryAgent::deviceDiscovered,this,&Bluetooth::addDevice);
    connect(agent,&QBluetoothDeviceDiscoveryAgent::finished,this,&Bluetooth::scanFinished);
    connect(localDevice,&QBluetoothLocalDevice::pairingFinished,this,&Bluetooth::pairingDone);
    connect(localDevice,&QBluetoothLocalDevice::error,this,&Bluetooth::enableList);

    //socket signals
    connect(socket,&QBluetoothSocket::connected,this,&Bluetooth::socketConnected);
    connect(socket,&QBluetoothSocket::readyRead,this,&Bluetooth::readData);
    connect(socket,&QBluetoothSocket::disconnected,this,&Bluetooth::disconnectDevice);
    connect(socket,SIGNAL(error(QBluetoothSocket::SocketError)),this,SLOT(connectionLost()));
}

Bluetooth::~Bluetooth()
{

}

void Bluetooth::checkDeviceBluetooth()
{
    //check if Bluetooth is available on this device
    if(!localDevice->isValid())
    {
        QMessageBox::critical(nullptr,"Info","Bluetooth is not available on this device");
        //update MainWindow
        emit sendToTextBrowser("Bluetooth: no device found");
    }
    else
        emit sendToTextBrowser("Bluetooth: ready"); //update MainWindow

    //check for bluetooth power ON
    if(localDevice->HostPoweredOff == 0)
    {
        localDevice->powerOn();
        QThread::sleep(3); // delay for uploading Bluetooth module
    }
}

void Bluetooth::agentStart()
{
    //scan for bluetooth devices
    socket->blockSignals(false); // enable socket disconnet signal
    localDevice->setHostMode(QBluetoothLocalDevice::HostDiscoverable); // make localDevice visible
    addressList->clear();
    agent->start();

    //update MainWindow
    m_listWidget->clear();
    emit sendToTextBrowser("Scanning...");
}

void Bluetooth::agentStop()
{
    agent->stop();
    //update MainWindow
    emit sendToTextBrowser("");
}

void Bluetooth::addDevice(const QBluetoothDeviceInfo &info)
{
    //find devices
    QString label = QString("%1").arg(info.name());

    if(label == "")
        label = QString("%1").arg(info.address().toString());

    QList<QListWidgetItem *> items = m_listWidget->findItems(label,Qt::MatchExactly);

    if(items.empty())
    {
        QListWidgetItem *item = new QListWidgetItem(label);
        QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(info.address());
        if(pairingStatus == QBluetoothLocalDevice::Paired || pairingStatus == QBluetoothLocalDevice::AuthorizedPaired)
            item->QListWidgetItem::setForeground(QColor(Qt::blue));
        else
            item->QListWidgetItem::setForeground(QColor(Qt::black));
        // check for low energy bluetooth device
        if(info.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration)
        {
            QString type = "  LE";
            item->setText(label + type);
        }
        addressList->push_back(info.address()); // save device address

        //update MainWindow
        m_listWidget->addItem(item);
    }
}

void Bluetooth::scanFinished()
{
    //show found devices
    if(m_listWidget->count() == 0)
        QMessageBox::critical(nullptr,"Scan Failure","No devices found!");
    else
    {
        //update MainWindow
        emit sendToTextBrowser("Devices found");
    }
    //update MainWindow
    emit enableObjectsMainWindow();
}

void Bluetooth::pairingDone(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing)
{
    //change device color status
    int number = addressList->indexOf(address);
    QListWidgetItem *item = m_listWidget->item(number);
    if(pairing == QBluetoothLocalDevice::Paired || pairing == QBluetoothLocalDevice::AuthorizedPaired)
        item->QListWidgetItem::setForeground(QColor(Qt::blue));
    else
        item->QListWidgetItem::setForeground(QColor(Qt::black));
    QString text = item->text();
    QString cutText = text.left(text.indexOf('\n')); // remove words connecting/disconnecting
    item->setText(cutText);

    //update MainWindow
    emit sendToTextBrowser("Devices found");
    m_listWidget->setEnabled(true); // enable listWidget
}

void Bluetooth::listWidgetClicked(QListWidgetItem *item)
{
    //pair or unpair device by click
    if(agent->isActive())
    {
        agent->stop(); // stop for scanning
        scanFinished();
    }
    if(item->text() != "P-Climate Sensor")
    {
        QMessageBox::warning(nullptr,"Attention","Connection can be set only to P-Climate Sensor");
        return;
    }
    QBluetoothAddress address = addressList->at(m_listWidget->row(item)); // get address from list
    QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(address);
    QMessageBox msgBox; //connect/disconnect
    QString text; // text for connecting/disconnecting window
    if(pairingStatus == QBluetoothLocalDevice::Paired || pairingStatus == QBluetoothLocalDevice::AuthorizedPaired)
    {
        //Disconnect to device
        msgBox.setText("Connection Options");
        QPushButton *unpair = new QPushButton("Unpair");
        msgBox.addButton(unpair,QMessageBox::YesRole);
        QPushButton *connectButton = new QPushButton("Connect");
        msgBox.addButton(connectButton,QMessageBox::NoRole);
        msgBox.setStandardButtons(QMessageBox::Cancel);
        int choice = msgBox.exec();
        switch (choice)
        {
            case QMessageBox::YesRole:
            {
                localDevice->requestPairing(address,QBluetoothLocalDevice::Unpaired);
                text = item->text() +  "\n Disconnecting...";
                item->setText(text);
                m_listWidget->setEnabled(false); // disable listWidget
                break;
            }
            case QMessageBox::NoRole:
            {
                socket->connectToService(address,QBluetoothUuid(QBluetoothUuid::SerialPort));
                socket->open(QIODevice::ReadWrite);

                //update MainWindow
                m_listWidget->setEnabled(false); // disable listWidget
                emit sendToTextBrowser("Connecting...");
                break;
            }
            case QMessageBox::Cancel:
            break;
            default:
            break;
        }
    }
    else
    {
        //Connect to device
        msgBox.setText("Pair Device");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int choice = msgBox.exec();
        switch (choice)
        {
            case QMessageBox::Yes:
            {
                localDevice->requestPairing(address,QBluetoothLocalDevice::Paired);
                text = item->text() + "\n Pairing...";
                item->setText(text);

                //update MainWindow
                emit sendToTextBrowser("Pairing...");
                m_listWidget->setEnabled(false); // disable listWidget
                break;
            }
            case QMessageBox::No:
            break;
            default:
            break;
        }
    }
    m_listWidget->clearSelection(); //deselect listWidget
}

bool Bluetooth::checkAgentState()
{
    if(agent->isActive())
        return true;
    return false;
}

void Bluetooth::socketConnected()
{
    //refresh display elements
    if(socket->isOpen())
        emit sendToTextBrowser("Transmission set. Updating...");

    emit updateElements(2); //update MainWindow and show pushButton_Disconnect

    m_listWidget->clear();
    QString name_device = socket->peerName();
    m_listWidget->addItem(name_device); // show device name
}

void Bluetooth::readData()
{
    //read Data from device
    if(!socket)
    {
        data = "No Data";
        printData(data);
        data.clear();
        return;
    }

    while(socket->canReadLine())
    {
        QString data_recieved = socket->readLine().simplified() + "\n"; // read data from socket and remove whitespace
        if(data_recieved.contains("endline",Qt::CaseInsensitive))
        {
            printData(data); // view data
            data.clear(); // clear data lines
            return;
        }
        data += data_recieved;
    }
}

void Bluetooth::printData(QString &data)
{
    //view data from sensor in real time
    m_listWidget->clear();
    QString name_device = socket->peerName();
    m_listWidget->addItem(name_device); // show device name
    m_listWidget->addItem(data); // show data
}

void Bluetooth::disconnectDevice()
{
    //disconnect from device
    socket->blockSignals(true); // disable socket disconnet signal
    socket->disconnectFromService();
}

void Bluetooth::connectionLost()
{
    //disconnect from device on lost connection
    disconnectDevice();
    QMessageBox::critical(nullptr,"Connection lost","Check sensor");
}

void Bluetooth::enableList()
{
    //listWidget enable and clear connection status on pairing error
    m_listWidget->setEnabled(true);
    for(int k = 0; k < addressList->size(); k++)
    {
        QListWidgetItem *item = m_listWidget->item(k);
        QBluetoothLocalDevice::Pairing pairing = localDevice->pairingStatus(addressList->at(k));
        if(pairing == QBluetoothLocalDevice::Paired || pairing == QBluetoothLocalDevice::AuthorizedPaired)
            item->QListWidgetItem::setForeground(QColor(Qt::blue));
        else
            item->QListWidgetItem::setForeground(QColor(Qt::black));
        QString text = item->text();
        QString cutText = text.left(text.indexOf('\n')); // remove words connecting/disconnecting
        item->setText(cutText);

        //update MainWindow
        emit sendToTextBrowser("Devices found");
    }
    QMessageBox::critical(nullptr,"Error","Can't pair device");
}
