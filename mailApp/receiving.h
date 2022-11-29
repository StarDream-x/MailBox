/**
* @author Wang Haonan (Student-ID:2020302191718)
* @date 2022-11-29
*/

#ifndef RECEIVING_H
#define RECEIVING_H

#include "mailpop3.h"
#include "user.h"

#include <QWidget>
#include <receivedmail.h>

namespace Ui {
class Receiving;
}

class Receiving : public QWidget
{
    Q_OBJECT

public:
    explicit Receiving(QWidget *parent = nullptr);
    ~Receiving();
    void setUser(user* use);
    void doConnect();

public slots:
    void onAuthenticated();
    void onSSLError();
    void onAuthError();
    void onConnectError();
    void handleList(int code);
    void handleRetr(int code);
    void handleDele(int code);
    void onDeleteMailButtonPressed();
    void onBackButtonPressed();

private:
    QString getDomainName();
    void displayMails();

private:
    Ui::Receiving *ui;
    user* use = nullptr;
    QxtPop3* pop = nullptr;
    int mailCount = 0;
    int receivedMailCount = 0;
    QList<ReceivedMail> mails;

signals:
    void closed();
};

#endif // RECEIVING_H
