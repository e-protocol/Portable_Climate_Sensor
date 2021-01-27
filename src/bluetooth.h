#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth>
#include <QListWidget>
#include <QMessageBox>
#include <QThread>
#include <QMainWindow>
#include <QString>

class Bluetooth : public QObject
{
    Q_OBJECT
private:
    QBluetoothLocalDevice *localDevice;
    QBluetoothDeviceDiscoveryAgent *agent;
    QList<QBluetoothAddress> *addressList; //create address list;
    QBluetoothSocket *socket;
    QList<QListWidgetItem *> *list_items;
    QListWidget *m_listWidget;
    QString data; // data from device
    void checkDeviceBluetooth();

private slots:
    void addDevice(const QBluetoothDeviceInfo &info);
    void scanFinished();
    void pairingDone(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing);
    void socketConnected(); //refresh display elements
    void readData(); //read Data from device
    void printData(QString &data); //view data from sensor in real time
    void enableList(); //listWidget enable and clear connection status on pairing error
    void connectionLost();

public:
    Bluetooth(QListWidget *listWidget);
    ~Bluetooth();
    void agentStart();
    void agentStop();
    void listWidgetClicked(QListWidgetItem *item);
    bool checkAgentState();
    void disconnectDevice(); //disconnect from device if connection lost

signals:
    void sendToTextBrowser(const QString text);
    void sendToListWidget(QListWidgetItem item);
    void enableObjectsMainWindow();
    void updateElements(int pushButton_show);
};

#endif // BLUETOOTH_H
