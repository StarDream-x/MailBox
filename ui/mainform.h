/**
 * @brief Email Client Application
 *
 * @author Wang Haonan (Student-ID:2020302191718)
 *
 */

#ifndef MAINFORM_H
#define MAINFORM_H

#include "src/MySmtp.h"
#include "src/clientpop.h"
#include <QWidget>

namespace Ui {
    class MainForm;
}

class Draft {
private:
    QString receiver;
    QString subject;
    QString body;
    QStringList attachments;

public:
    explicit Draft() {}
    ~Draft() {}
    QString get_receiver() const { return receiver; }
    QString get_subject() const { return subject; }
    QString get_body() const { return body; }
    QStringList get_attachments() const { return attachments; }
    void set_receiver(const QString& receiver) { this->receiver = receiver; }
    void set_subject(const QString& subject) { this->subject = subject; }
    void set_body(const QString& body) { this->body = body; }
    void set_attachments(const QStringList& attachments) { this->attachments = attachments; }
    void clear() {
        this->receiver = QString();
        this->subject = QString();
        this->body = QString();
        this->attachments = QStringList();
    }
};

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

public slots:
    void login_button_clicked();
    void logout_button_clicked();
    void new_message_button_clicked();
    void refresh_button_clicked();

private:
    Ui::MainForm *ui;
    MySmtp *smtp_client = nullptr;
    ClientPop *pop3_client = nullptr;
    Draft* draft = new Draft();

private:
    void destroy_clients();
    void set_control_state(bool);
    void refresh_message_list();
};

#endif // MAINFORM_H
