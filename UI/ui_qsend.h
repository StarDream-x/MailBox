/********************************************************************************
** Form generated from reading UI file 'qsend.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSEND_H
#define UI_QSEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qsend
{
public:
    QGroupBox *sending;
    QLabel *label_5;
    QLineEdit *to;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *sendButton;
    QLineEdit *subject;
    QPushButton *backButton;
    QPlainTextEdit *body;

    void setupUi(QWidget *Qsend)
    {
        if (Qsend->objectName().isEmpty())
            Qsend->setObjectName("Qsend");
        Qsend->resize(755, 425);
        Qsend->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/1.jpg);"));
        sending = new QGroupBox(Qsend);
        sending->setObjectName("sending");
        sending->setGeometry(QRect(100, 40, 491, 371));
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
        to = new QLineEdit(sending);
        to->setObjectName("to");
        to->setGeometry(QRect(99, 20, 361, 20));
        to->setStyleSheet(QString::fromUtf8("background-color: rgba(1, 91, 249, 200);\n"
"color: rgb(255, 255, 255);"));
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
        sendButton = new QPushButton(sending);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(290, 330, 80, 18));
        sendButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));
        subject = new QLineEdit(sending);
        subject->setObjectName("subject");
        subject->setGeometry(QRect(100, 60, 361, 20));
        subject->setStyleSheet(QString::fromUtf8("background-color: rgba(1, 91, 249, 200);\n"
"color: rgb(255, 255, 255);"));
        backButton = new QPushButton(sending);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(140, 330, 80, 18));
        backButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));
        body = new QPlainTextEdit(sending);
        body->setObjectName("body");
        body->setGeometry(QRect(100, 110, 361, 201));
        body->setStyleSheet(QString::fromUtf8("background-color: rgba(1, 91, 249, 200);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(Qsend);

        QMetaObject::connectSlotsByName(Qsend);
    } // setupUi

    void retranslateUi(QWidget *Qsend)
    {
        Qsend->setWindowTitle(QCoreApplication::translate("Qsend", "Form", nullptr));
        sending->setTitle(QString());
        label_5->setText(QCoreApplication::translate("Qsend", "Receiver", nullptr));
        label_6->setText(QCoreApplication::translate("Qsend", "Subject", nullptr));
        label_7->setText(QCoreApplication::translate("Qsend", "Message", nullptr));
        sendButton->setText(QCoreApplication::translate("Qsend", "SEND>>", nullptr));
        backButton->setText(QCoreApplication::translate("Qsend", "<<BACK", nullptr));
        body->setPlainText(QString());
    } // retranslateUi

};

namespace Ui {
    class Qsend: public Ui_Qsend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSEND_H
