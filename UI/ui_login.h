/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Index
{
public:
    QGroupBox *login;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *loginButton;
    QLineEdit *account;
    QLineEdit *password;
    QPushButton *exitButton;

    void setupUi(QWidget *Index)
    {
        if (Index->objectName().isEmpty())
            Index->setObjectName("Index");
        Index->resize(755, 425);
        Index->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/1.jpg);"));
        login = new QGroupBox(Index);
        login->setObjectName("login");
        login->setGeometry(QRect(260, 120, 281, 191));
        login->setStyleSheet(QString::fromUtf8("#login{background-color: rgba(0, 93, 250, 100);}\n"
""));
        label = new QLabel(login);
        label->setObjectName("label");
        label->setGeometry(QRect(73, 15, 101, 41));
        label->setStyleSheet(QString::fromUtf8("font: 15pt \"Comic Sans MS\";\n"
"color: rgb(255, 255, 255);"));
        label->setTextFormat(Qt::RichText);
        label->setScaledContents(false);
        label->setWordWrap(false);
        label->setOpenExternalLinks(false);
        label_3 = new QLabel(login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 60, 101, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Comic Sans MS\";\n"
"color: rgb(255, 255, 255);"));
        label_3->setTextFormat(Qt::RichText);
        label_3->setScaledContents(false);
        label_3->setWordWrap(false);
        label_3->setOpenExternalLinks(false);
        label_4 = new QLabel(login);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(15, 89, 81, 41));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Comic Sans MS\";\n"
"color: rgb(255, 255, 255);"));
        label_4->setTextFormat(Qt::RichText);
        label_4->setScaledContents(false);
        label_4->setWordWrap(false);
        label_4->setOpenExternalLinks(false);
        loginButton = new QPushButton(login);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(50, 140, 80, 18));
        loginButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));
        account = new QLineEdit(login);
        account->setObjectName("account");
        account->setGeometry(QRect(100, 70, 151, 20));
        account->setStyleSheet(QString::fromUtf8("background-color: rgba(1, 91, 249, 200);\n"
"color: rgb(255, 255, 255);"));
        password = new QLineEdit(login);
        password->setObjectName("password");
        password->setGeometry(QRect(100, 100, 151, 20));
        password->setStyleSheet(QString::fromUtf8("background-color: rgba(1, 91, 249, 200);\n"
"color: rgb(255, 255, 255);"));
        password->setEchoMode(QLineEdit::Password);
        exitButton = new QPushButton(login);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(160, 140, 80, 18));
        exitButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(Index);

        QMetaObject::connectSlotsByName(Index);
    } // setupUi

    void retranslateUi(QWidget *Index)
    {
        Index->setWindowTitle(QCoreApplication::translate("Index", "Widget", nullptr));
        login->setTitle(QString());
        label->setText(QCoreApplication::translate("Index", "LOGIN HERE", nullptr));
        label_3->setText(QCoreApplication::translate("Index", "Account:", nullptr));
        label_4->setText(QCoreApplication::translate("Index", "Password:", nullptr));
        loginButton->setText(QCoreApplication::translate("Index", "LOGIN", nullptr));
        account->setText(QString());
        exitButton->setText(QCoreApplication::translate("Index", "EXIST", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Index: public Ui_Index {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
