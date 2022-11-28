/**
 * @brief Email Client Application
 *
 * @author Wang Haonan (Student-ID:2020302191718)
 *
 */

#ifndef NEWMESSAGEFORM_H
#define NEWMESSAGEFORM_H

#include "ui/mainform.h"
#include <QWidget>

namespace Ui {
    class NewMessageForm;
}

class NewMessageForm : public QWidget
{
    Q_OBJECT

public:
    explicit NewMessageForm(Draft* draft, MySmtp* smtp_client, QWidget *parent = nullptr);
    ~NewMessageForm();

public slots:
    void send_button_clicked();
    void draft_button_clicked();
    void discard_message_button_clicked();
    void add_attachment_button_clicked();
    void remove_attachment_button_clicked();

private:
    Ui::NewMessageForm *ui;
    MySmtp* smtp_client = nullptr;
    Draft* draft = nullptr;
};

#endif // NEWMESSAGEFORM_H
