/********************************************************************************
** Form generated from reading UI file 'qhome.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHOME_H
#define UI_QHOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qhome
{
public:
    QPushButton *writeButton;
    QPushButton *logoutButtton;
    QGroupBox *receiving;
    QPushButton *receiveButton;
    QGroupBox *writing;

    void setupUi(QWidget *Qhome)
    {
        if (Qhome->objectName().isEmpty())
            Qhome->setObjectName("Qhome");
        Qhome->resize(755, 425);
        Qhome->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/1.jpg);"));
        writeButton = new QPushButton(Qhome);
        writeButton->setObjectName("writeButton");
        writeButton->setGeometry(QRect(120, 250, 121, 31));
        writeButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));
        logoutButtton = new QPushButton(Qhome);
        logoutButtton->setObjectName("logoutButtton");
        logoutButtton->setGeometry(QRect(240, 330, 151, 31));
        logoutButtton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));
        receiving = new QGroupBox(Qhome);
        receiving->setObjectName("receiving");
        receiving->setGeometry(QRect(390, 60, 221, 171));
        receiving->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 93, 250, 0);\n"
"background-image: url(:/new/prefix1/receiving4.png);"));
        receiveButton = new QPushButton(Qhome);
        receiveButton->setObjectName("receiveButton");
        receiveButton->setGeometry(QRect(440, 250, 121, 31));
        receiveButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));
        writing = new QGroupBox(Qhome);
        writing->setObjectName("writing");
        writing->setGeometry(QRect(100, 60, 151, 171));
        writing->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 93, 250, 0);\n"
"background-image: url(:/new/prefix1/writing4.png);"));

        retranslateUi(Qhome);

        QMetaObject::connectSlotsByName(Qhome);
    } // setupUi

    void retranslateUi(QWidget *Qhome)
    {
        Qhome->setWindowTitle(QCoreApplication::translate("Qhome", "Form", nullptr));
        writeButton->setText(QCoreApplication::translate("Qhome", "Write", nullptr));
        logoutButtton->setText(QCoreApplication::translate("Qhome", "logout", nullptr));
        receiving->setTitle(QString());
        receiveButton->setText(QCoreApplication::translate("Qhome", "Receive", nullptr));
        writing->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class Qhome: public Ui_Qhome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHOME_H
