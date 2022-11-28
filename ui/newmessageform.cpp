/**
 * @brief Email Client Application
 *
 * @author Wang Haonan (Student-ID:2020302191718)
 *
 */

#include "newmessageform.h"
#include "ui_newmessageform.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItem>

NewMessageForm::NewMessageForm(Draft* draft, MySmtp* smtp_client, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewMessageForm),
    smtp_client(smtp_client),
    draft(draft)
{
    ui->setupUi(this);
    connect(ui->send_button, SIGNAL(clicked()), this, SLOT(send_button_clicked()));
    connect(ui->draft_button, SIGNAL(clicked()), this, SLOT(draft_button_clicked()));
    connect(ui->discard_button, SIGNAL(clicked()), this, SLOT(discard_message_button_clicked()));
    connect(ui->add_attachment_button, SIGNAL(clicked()), this, SLOT(add_attachment_button_clicked()));
    connect(ui->remove_attachment_button, SIGNAL(clicked()), this, SLOT(remove_attachment_button_clicked()));
    if (draft != nullptr) {
        ui->receiver_text->setText(draft->get_receiver());
        ui->subject_text->setText(draft->get_subject());
        ui->body_text->setPlainText(draft->get_body());
        ui->attachment_list->addItems(draft->get_attachments());
    }
}

NewMessageForm::~NewMessageForm() {
    delete ui;
}

void NewMessageForm::send_button_clicked() {
    if (smtp_client == nullptr) {
        QMessageBox::critical(nullptr, "Error", "Please login");
        return;
    }
    auto receiver = ui->receiver_text->text();
    auto subject = ui->subject_text->text();
    auto body = ui->body_text->toPlainText();
    smtp_client->SendEmail(receiver, subject, body);
    if (smtp_client->ErrorNum == 0) {
        QMessageBox::information(this, "Success", "Email was sent");
        close();
    } else {
        QString error_text;
        switch (smtp_client->ErrorNum) {
        case 1:
            error_text = "User does not exist";
            break;
        case 3:
            error_text = "Invalid response";
            break;
        case 4:
            error_text = "File does not exist";
            break;
        case 5:
            error_text = "Cannot open file";
            break;
        default:
            error_text = "Unknown error";
            break;
        }
        QMessageBox::critical(this, "Failure", error_text);
    }
}

void NewMessageForm::draft_button_clicked() {
    if (draft != nullptr) {
        draft->set_receiver(ui->receiver_text->text());
        draft->set_subject(ui->subject_text->text());
        draft->set_body(ui->body_text->toPlainText());
        QStringList list;
        for (int i = 0; i < ui->attachment_list->count(); ++i) {
            list.append(ui->attachment_list->item(i)->text());
        }
        draft->set_attachments(list);
    }
    close();
}

void NewMessageForm::discard_message_button_clicked() {
    if (draft != nullptr) {
        draft->clear();
    }
    close();
}

void NewMessageForm::add_attachment_button_clicked() {
    if (ui->attachment_list->count() >= MaxNumOfAttachment) {
        QMessageBox::warning(this, "Notice", "You've reached the maximum number of attachments");
        return;
    }

    QFileDialog dialog;
    QString path = dialog.getOpenFileName(this, "Open Attachment");
    if (path.length() > 0) {
        ui->attachment_list->addItem(path);
    }
}

void NewMessageForm::remove_attachment_button_clicked() {
    ui->attachment_list->takeItem(ui->attachment_list->currentRow());
}
