/********************************************************************************
** Form generated from reading UI file 'failLogin.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAILLOGIN_H
#define UI_FAILLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *closeButton;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        closeButton = new QDialogButtonBox(Dialog);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(140, 180, 91, 32));
        closeButton->setOrientation(Qt::Horizontal);
        closeButton->setStandardButtons(QDialogButtonBox::Close);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 100, 191, 61));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        retranslateUi(Dialog);
        QObject::connect(closeButton, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(closeButton, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Account or Password ERROR!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAILLOGIN_H
