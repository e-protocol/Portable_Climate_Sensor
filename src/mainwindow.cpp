/********************************************************************************
 * Created by E-Protocol
 * https://github.com/e-protocol
********************************************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>
#include <QScreen>
#include <javarequest.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listWidget = ui->listWidget;
    pushButton_Find = ui->pushButton_Find;
    pushButton_Disconnect = ui->pushButton_Disconnect;
    pushButton_Quit = ui->pushButton_Quit;
    textBrowser = ui->textBrowser;

    //init bluetooth device
    bluetooth = new Bluetooth(listWidget);
    checkAccess();

    //set bluetooth listeners
    connect(bluetooth,&Bluetooth::sendToTextBrowser,this,&MainWindow::updateTextBrowser);
    connect(bluetooth,&Bluetooth::enableObjectsMainWindow,this,&MainWindow::enableObjects);
    connect(bluetooth,&Bluetooth::updateElements,this,&MainWindow::positionElements);

    //style
    textBrowser->setStyleSheet("border:none; font-size: 35px;");
    listWidget->setStyleSheet("font-size: 50px");

    //update mainWindow and show pushButton_Find
    positionElements(1);

    //set pushButton_Find listener
    connect(pushButton_Find,&QPushButton::clicked,this,&MainWindow::startScan);
    //set pushButton_Disconnect listener
    connect(pushButton_Disconnect,&QPushButton::clicked,bluetooth,&Bluetooth::disconnectDevice);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Bluetooth part
//************************************************************************************************************************

void MainWindow::startScan()
{
    //check location access
    if(!getAccess())
    {
        QMessageBox::critical(nullptr,"Access Denied!","To proceed allow app to access GPS");
        checkAccess();
        return;
    }

     listWidget->setEnabled(true); //enable listWidget

    if(bluetooth->checkAgentState())
    {
        pushButton_Find->setText("Find devices");
        bluetooth->agentStop(); //stop bluetooth scan
    }
    else
    {
        pushButton_Find->setText("Stop");
        bluetooth->agentStart(); //start bluetooth scan
    }
}

void MainWindow::on_pushButton_Disconnect_clicked()
{
    positionElements(1);
    listWidget->clear();
    listWidget->setEnabled(true); // enable listWidget
    updateTextBrowser("Bluetooth: ready");
}

void MainWindow::enableObjects()
{
    pushButton_Find->setText("Find devices");
    listWidget->setEnabled(true); // enable listWidget
}

void MainWindow::updateTextBrowser(const QString text)
{
    textBrowser->clear();
    textBrowser->insertHtml(text);
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    bluetooth->listWidgetClicked(item);
}

//Bluetooth part END
//************************************************************************************************************************




//Application View part
//************************************************************************************************************************

void MainWindow::positionElements(int pushButton_show)
{
    //set position and display elements on screen
    //screen size
    QScreen *screen = QApplication::screens().at(0);
    int height = screen->availableSize().height();
    int width = screen->availableSize().width();
    this->setGeometry(0,0,width,height);

    //elements parameteres
    //pushButton_Find
    int x_pushButton_Find = static_cast<int>(width * 0.1);
    int y_pushButton_Find = static_cast<int>(height * 0.1);
    int h_pushButton_Find = 150;
    int w_pushButton_Find = static_cast<int>(width * 0.35);
    //textBrowser
    int x_textBrowser = static_cast<int>(width * 0.5);
    int y_textBrowser = static_cast<int>(height * 0.1);
    int h_textBrowser = 150;
    int w_textBrowser = static_cast<int>(width * 0.4);
    //listWidget
    int padding = 20;
    int x_listWidget = static_cast<int>(width * 0.1);
    int y_listWidget = static_cast<int>(height * 0.1) + h_pushButton_Find + padding;
    int h_listWidget = static_cast<int>((height - y_listWidget) * 0.8);
    int w_listWidget = static_cast<int>(width * 0.8);
    //pushButton_Quit
    int x_pushButton_Quit = static_cast<int>(width * 0.1);
    int y_pushButton_Quit = y_listWidget + h_listWidget + padding;

    //display pushButton
    if(pushButton_show == 1)
    {
        pushButton_Disconnect->hide();
        pushButton_Find->setGeometry(x_pushButton_Find, y_pushButton_Find , w_pushButton_Find, h_pushButton_Find);
        pushButton_Find->show();
    }
    else if(pushButton_show == 2)
    {
        pushButton_Find->hide();
        pushButton_Disconnect->setGeometry(x_pushButton_Find, y_pushButton_Find , w_pushButton_Find, h_pushButton_Find);
        pushButton_Disconnect->show();
    }

    //display elements
    textBrowser->setGeometry(x_textBrowser, y_textBrowser, w_textBrowser, h_textBrowser);
    listWidget->setGeometry(x_listWidget, y_listWidget, w_listWidget, h_listWidget);
    pushButton_Quit->setGeometry(x_pushButton_Quit, y_pushButton_Quit,w_pushButton_Find, h_pushButton_Find);
}

//Application View part END
//************************************************************************************************************************

void MainWindow::on_pushButton_Quit_clicked()
{
    qApp->exit(0);
}

void MainWindow::checkAccess()
{
    checkPermissions();
    if(!getAccess())
        turnGpsOn();
}
