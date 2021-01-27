/********************************************************************************
 * Created by E-Protocol
 * https://github.com/e-protocol
********************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <bluetooth.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    Bluetooth *bluetooth;
    QListWidget *listWidget;
    QPushButton *pushButton_Find;
    QPushButton *pushButton_Disconnect;
    QPushButton *pushButton_Quit;
    QTextBrowser *textBrowser;
    void checkAccess();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTextBrowser(const QString text);
    void enableObjects();
    void startScan(); //scan for bluetooth devices
    void on_pushButton_Disconnect_clicked(); //Disconnect from device
    void on_listWidget_itemClicked(QListWidgetItem *item); //pair or unpair device by click
    void positionElements(int pushButton_show); //set position and display elements on screen
    void on_pushButton_Quit_clicked(); //exit application
};


#endif // MAINWINDOW_H
