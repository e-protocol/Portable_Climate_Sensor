/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_Disconnect;
    QTextBrowser *textBrowser;
    QListWidget *listWidget;
    QPushButton *pushButton_Quit;
    QPushButton *pushButton_Find;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_Disconnect = new QPushButton(centralwidget);
        pushButton_Disconnect->setObjectName(QString::fromUtf8("pushButton_Disconnect"));
        pushButton_Disconnect->setGeometry(QRect(40, 90, 161, 61));
        pushButton_Disconnect->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 41, 41);"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(210, 20, 181, 131));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(40, 170, 241, 192));
        pushButton_Quit = new QPushButton(centralwidget);
        pushButton_Quit->setObjectName(QString::fromUtf8("pushButton_Quit"));
        pushButton_Quit->setGeometry(QRect(40, 370, 161, 61));
        pushButton_Quit->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        pushButton_Find = new QPushButton(centralwidget);
        pushButton_Find->setObjectName(QString::fromUtf8("pushButton_Find"));
        pushButton_Find->setGeometry(QRect(40, 20, 161, 61));
        pushButton_Find->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 210, 22);"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_Disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        pushButton_Quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        pushButton_Find->setText(QCoreApplication::translate("MainWindow", "Find Devices", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
