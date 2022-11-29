/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
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
            Index->setObjectName(QStringLiteral("Index"));
        Index->resize(755, 425);
        Index->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/1.jpg);"));
        login = new QGroupBox(Index);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(260, 120, 281, 191));
        login->setStyleSheet(QLatin1String("#login{background-color: rgba(0, 93, 250, 100);}\n"
""));
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(73, 15, 101, 41));
        label->setStyleSheet(QLatin1String("font: 15pt \"Comic Sans MS\";\n"
"color: rgb(255, 255, 255);"));
        label->setTextFormat(Qt::RichText);
        label->setScaledContents(false);
        label->setWordWrap(false);
        label->setOpenExternalLinks(false);
        label_3 = new QLabel(login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 60, 101, 41));
        label_3->setStyleSheet(QLatin1String("font: 12pt \"Comic Sans MS\";\n"
"color: rgb(255, 255, 255);"));
        label_3->setTextFormat(Qt::RichText);
        label_3->setScaledContents(false);
        label_3->setWordWrap(false);
        label_3->setOpenExternalLinks(false);
        label_4 = new QLabel(login);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(15, 89, 81, 41));
        label_4->setStyleSheet(QLatin1String("font: 12pt \"Comic Sans MS\";\n"
"color: rgb(255, 255, 255);"));
        label_4->setTextFormat(Qt::RichText);
        label_4->setScaledContents(false);
        label_4->setWordWrap(false);
        label_4->setOpenExternalLinks(false);
        loginButton = new QPushButton(login);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(50, 140, 80, 18));
        loginButton->setStyleSheet(QLatin1String("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));
        account = new QLineEdit(login);
        account->setObjectName(QStringLiteral("account"));
        account->setGeometry(QRect(100, 70, 151, 20));
        account->setStyleSheet(QLatin1String("background-color: rgba(1, 91, 249, 200);\n"
"color: rgb(255, 255, 255);"));
        password = new QLineEdit(login);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(100, 100, 151, 20));
        password->setStyleSheet(QLatin1String("background-color: rgba(1, 91, 249, 200);\n"
"color: rgb(255, 255, 255);"));
        password->setEchoMode(QLineEdit::Password);
        exitButton = new QPushButton(login);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(160, 140, 80, 18));
        exitButton->setStyleSheet(QLatin1String("font: 700 9pt \"System\";\n"
"background-color: rgba(12, 57, 134, 200);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(Index);

        QMetaObject::connectSlotsByName(Index);
    } // setupUi

    void retranslateUi(QWidget *Index)
    {
        Index->setWindowTitle(QApplication::translate("Index", "Widget", Q_NULLPTR));
        login->setTitle(QString());
        label->setText(QApplication::translate("Index", "LOGIN HERE", Q_NULLPTR));
        label_3->setText(QApplication::translate("Index", "Account:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Index", "Password:", Q_NULLPTR));
        loginButton->setText(QApplication::translate("Index", "LOGIN", Q_NULLPTR));
        account->setText(QString());
        exitButton->setText(QApplication::translate("Index", "EXIST", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Index: public Ui_Index {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
