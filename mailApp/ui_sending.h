/********************************************************************************
** Form generated from reading UI file 'sending.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDING_H
#define UI_SENDING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SendUI
{
public:
    QGroupBox *sending;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;

    void setupUi(QWidget *SendUI)
    {
        if (SendUI->objectName().isEmpty())
            SendUI->setObjectName("SendUI");
        SendUI->resize(759, 427);
        SendUI->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/1.jpg);"));
        sending = new QGroupBox(SendUI);
        sending->setObjectName("sending");
        sending->setGeometry(QRect(110, 30, 491, 371));
        sending->setStyleSheet(QString::fromUtf8("#sending{background-color: rgba(0, 93, 250, 100);}"));
        label_5 = new QLabel(sending);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 10, 51, 41));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"Comic Sans MS\";\n"
"color: rgb(255, 255, 255);"));
        label_5->setTextFormat(Qt::RichText);
        label_5->setScaledContents(false);
        label_5->setWordWrap(false);
        label_5->setOpenExternalLinks(false);
        lineEdit_3 = new QLineEdit(sending);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(99, 20, 361, 20));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgba(1, 91, 249, 200);"));
        label_6 = new QLabel(sending);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 50, 51, 41));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"Comic Sans MS\";\n"
"color: rgb(255, 255, 255);"));
        label_6->setTextFormat(Qt::RichText);
        label_6->setScaledContents(false);
        label_6->setWordWrap(false);
        label_6->setOpenExternalLinks(false);
        label_7 = new QLabel(sending);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 90, 51, 41));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"Comic Sans MS\";\n"
"color: rgb(255, 255, 255);"));
        label_7->setTextFormat(Qt::RichText);
        label_7->setScaledContents(false);
        label_7->setWordWrap(false);
        label_7->setOpenExternalLinks(false);
        lineEdit_5 = new QLineEdit(sending);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(100, 100, 361, 201));
        lineEdit_5->setStyleSheet(QString::fromUtf8("background-color: rgba(1, 91, 249, 200);"));
        pushButton_2 = new QPushButton(sending);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(290, 330, 80, 18));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));
        lineEdit_4 = new QLineEdit(sending);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(100, 60, 361, 20));
        lineEdit_4->setStyleSheet(QString::fromUtf8("background-color: rgba(1, 91, 249, 200);"));
        pushButton_3 = new QPushButton(sending);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(140, 330, 80, 18));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(SendUI);

        QMetaObject::connectSlotsByName(SendUI);
    } // setupUi

    void retranslateUi(QWidget *SendUI)
    {
        SendUI->setWindowTitle(QCoreApplication::translate("SendUI", "Form", nullptr));
        sending->setTitle(QString());
        label_5->setText(QCoreApplication::translate("SendUI", "Receiver", nullptr));
        label_6->setText(QCoreApplication::translate("SendUI", "Subject", nullptr));
        label_7->setText(QCoreApplication::translate("SendUI", "Message", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SendUI", "SEND>>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SendUI", "<<BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendUI: public Ui_SendUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDING_H
