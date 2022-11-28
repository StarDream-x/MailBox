/**
 * @brief Email Client Application
 *
 * @author Wang Haonan (Student-ID:2020302191718)
 *
 */

#include "mainform.h"
#include "newmessageform.h"
#include "ui_mainform.h"
#include <QMessageBox>
#include <QStandardItem>

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    connect(ui->login_button, SIGNAL(clicked()), this, SLOT(login_button_clicked()));
    connect(ui->logout_button, SIGNAL(clicked()), this, SLOT(logout_button_clicked()));
    connect(ui->new_message_button, SIGNAL(clicked()), this, SLOT(new_message_button_clicked()));
    connect(ui->refresh_button, SIGNAL(clicked()), this, SLOT(refresh_button_clicked()));
    set_control_state(false);
}

MainForm::~MainForm() {
    destroy_clients();
    delete ui;
}

void MainForm::destroy_clients() {
    if (smtp_client != nullptr) {
        delete smtp_client;
        smtp_client = nullptr;
    }
    if (pop3_client != nullptr) {
        delete pop3_client;
        pop3_client = nullptr;
    }
}

void MainForm::set_control_state(bool is_login) {
    ui->smtp_host_text->setEnabled(!is_login);
    ui->pop3_host_text->setEnabled(!is_login);
    ui->username_text->setEnabled(!is_login);
    ui->password_text->setEnabled(!is_login);
    ui->login_button->setEnabled(!is_login);
    ui->logout_button->setEnabled(is_login);
    ui->new_message_button->setEnabled(is_login);
    ui->refresh_button->setEnabled(is_login);
    ui->message_list->setEnabled(is_login);
}

void MainForm::refresh_message_list() {
    try {
        auto response = pop3_client->get_message_list();
        if (!response.status) {
            throw Error("Failure", response.status_message);
        }
        ui->message_list->clear();
        ui->message_list->addItems(response.data);
    } catch (Error& error) {
        QMessageBox::critical(this, "Error", error.to_string());
    }
}

void MainForm::login_button_clicked() {
    auto username = ui->username_text->text();
    auto password = ui->password_text->text();
    auto pop3_host = ui->pop3_host_text->text();

    try {
        smtp_client = new MySmtp(username, password);
        smtp_client->Auth();
        if (smtp_client->ErrorNum != 0) {
            switch (smtp_client->ErrorNum) {
            case 2:
                throw Error("Login failed", "Incorrect username or password");
            case 3:
                throw Error("Login failed", "Invalid response");
            }
        }
        pop3_client = new ClientPop(pop3_host);
        pop3_client->authenticate(username, password);
    } catch (Error& error) {
        QMessageBox::critical(this, "Error", error.to_string());
        destroy_clients();
        return;
    }

    auto smtp_host = smtp_client->GetDomineName();
    ui->smtp_host_text->setText(smtp_host);
    set_control_state(true);
    refresh_message_list();
}

void MainForm::logout_button_clicked() {
    destroy_clients();
    set_control_state(false);
}

void MainForm::new_message_button_clicked() {
    auto new_message_form = new NewMessageForm(draft, smtp_client, this);
    new_message_form->setWindowFlags(new_message_form->windowFlags() | Qt::Dialog);
    new_message_form->setWindowModality(Qt::ApplicationModal);
    new_message_form->setAttribute(Qt::WA_DeleteOnClose);
    new_message_form->show();
}

void MainForm::refresh_button_clicked() {
    refresh_message_list();
}
