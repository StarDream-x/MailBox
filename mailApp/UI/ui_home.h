/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Home
{
public:
    QGroupBox *writing;
    QGroupBox *receiving;
    QPushButton *receiveButton;
    QPushButton *writeButton;
    QPushButton *logoutButtton;

    void setupUi(QWidget *Home)
    {
        if (Home->objectName().isEmpty())
            Home->setObjectName("Home");
        Home->resize(755, 425);
        Home->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/1.jpg);"));
        writing = new QGroupBox(Home);
        writing->setObjectName("writing");
        writing->setGeometry(QRect(160, 50, 151, 171));
        writing->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 93, 250, 0);\n"
"background-image: url(:/new/prefix1/writing4.png);\n"
"\n"
"\n"
""));
        receiving = new QGroupBox(Home);
        receiving->setObjectName("receiving");
        receiving->setGeometry(QRect(450, 50, 221, 171));
        receiving->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 93, 250, 0);\n"
"background-image: url(:/new/prefix1/receiving4.png);\n"
"\n"
""));
        receiveButton = new QPushButton(Home);
        receiveButton->setObjectName("receiveButton");
        receiveButton->setGeometry(QRect(500, 240, 121, 31));
        receiveButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));
        writeButton = new QPushButton(Home);
        writeButton->setObjectName("writeButton");
        writeButton->setGeometry(QRect(180, 240, 121, 31));
        writeButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));
        logoutButtton = new QPushButton(Home);
        logoutButtton->setObjectName("logoutButtton");
        logoutButtton->setGeometry(QRect(300, 320, 151, 31));
        logoutButtton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(Home);

        QMetaObject::connectSlotsByName(Home);
    } // setupUi

    void retranslateUi(QWidget *Home)
    {
        Home->setWindowTitle(QCoreApplication::translate("Home", "Form", nullptr));
        writing->setTitle(QString());
        receiving->setTitle(QString());
        receiveButton->setText(QCoreApplication::translate("Home", "Receive", nullptr));
        writeButton->setText(QCoreApplication::translate("Home", "Write", nullptr));
        logoutButtton->setText(QCoreApplication::translate("Home", "logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Home: public Ui_Home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
