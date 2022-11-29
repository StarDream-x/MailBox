/**
* @author Wang Haonan (Student-ID:2020302191718)
* @date 2022-11-29
*/

#include "receiving.h"
#include "qsslsocket.h"
#include "ui_receiving.h"

#include <QMessageBox>

Receiving::Receiving(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Receiving)
{
    ui->setupUi(this);
    QStringList headerText;
    headerText << "Sender" << "Subject" << "Body" << "Date";
    ui->mailTable->setColumnCount(4);
    for (int i = 0; i < ui->mailTable->columnCount(); ++i) {
        auto item = new QTableWidgetItem(headerText.at(i));
        QFont font = item->font();
        font.setBold(true);
        item->setFont(font);
        ui->mailTable->setHorizontalHeaderItem(i, item);
    }
    ui->mailTable->clearContents();

    pop = new QxtPop3(this);
    pop->sslSocket()->setProtocol(QSsl::TlsV1_2OrLater);
    pop->sslSocket()->setPeerVerifyMode(QSslSocket::VerifyPeer);
    pop->setStartTlsDisabled(true);
    connect(ui->deleteMailButton, SIGNAL(clicked()), this, SLOT(onDeleteMailButtonPressed()));
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(onBackButtonPressed()));
    connect(pop, SIGNAL(authenticated()), this, SLOT(onAuthenticated()));
    connect(pop, SIGNAL(connectionFailed(QByteArray)), this, SLOT(onConnectError()));
    connect(pop, SIGNAL(encryptionFailed(QByteArray)), this, SLOT(onSSLError()));
    connect(pop, SIGNAL(authenticationFailed(QByteArray)), this, SLOT(onAuthError()));
}

Receiving::~Receiving()
{
    delete ui;
}

QString Receiving::getDomainName() {
    QString username = use->getName();
    QString domainName = "pop.";
    int first = username.indexOf("@");
    QString emailType = username.mid(first + 1, username.size() - first - 1);
    domainName += emailType;
    return domainName;
}

void Receiving::doConnect() {
    QString domainName = getDomainName();
    quint16 port = 995;
    QString username = use->getName();
    QString password = use->getPassword();
    pop->setUsername(username.toLocal8Bit());
    pop->setPassword(password.toLocal8Bit());
    qDebug() << "POP3 connecting" << domainName << "port" << port << "username" << username;
    pop->connectToSecureHost(domainName.toLocal8Bit(), port);
}

void Receiving::onDeleteMailButtonPressed() {
    auto indexRangeList = ui->mailTable->selectedRanges();
    QList<int> rowsToRemove;
    for (auto indexRange : indexRangeList) {
        for (int index = indexRange.topRow(); index <= indexRange.bottomRow(); ++index) {
            QxtPop3Reply* reply = pop->deleteMessage(index + 1);
            connect(reply, SIGNAL(finished(int)), this, SLOT(handleDele(int)));
            qDebug() << "POP3 DELE" << index + 1;
            rowsToRemove.append(index);
        }
    }
    std::sort(rowsToRemove.begin(), rowsToRemove.end());
    for (int i = 0; i < rowsToRemove.count(); ++i) {
        ui->mailTable->removeRow(rowsToRemove[i] - i);
    }
}

void Receiving::onBackButtonPressed() {
    close();
    closed();
}

void Receiving::onAuthenticated() {
    qDebug() << "POP3 connected";
    mails.clear();
    mailCount = 0;
    receivedMailCount = 0;

    QxtPop3Reply* reply = pop->messageList();
    connect(reply, SIGNAL(finished(int)), this, SLOT(handleList(int)));
    qDebug() << "POP3 LIST";
}

void Receiving::handleList(int code) {
    switch (code) {
    case QxtPop3Reply::Ok:
        {
            QxtPop3ListReply* reply = dynamic_cast<QxtPop3ListReply*>(sender());
            if (reply == nullptr) {
                QMessageBox::critical(this, "Error", "Failed to fetch message");
                return;
            }
            mailCount = reply->list().size();
            qDebug() << "The server has" << mailCount << "email(s).";
            foreach (QxtPop3Reply::MessageInfo msginfo, reply->list()) {
                QxtPop3Reply* reply = pop->retrieveMessage(msginfo.id);
                connect(reply, SIGNAL(finished(int)), this, SLOT(handleRetr(int)));
                qDebug() << "POP3 RETR" << msginfo.id;
            }
        }
        break;
    default:
        qDebug() << "Bad return code:" << code;
        QMessageBox::critical(this, "Error", "Failed to fetch message");
        break;
    }
}

void Receiving::handleRetr(int code) {
    switch (code) {
    case QxtPop3Reply::Ok:
        {
            QxtPop3RetrReply* reply = dynamic_cast<QxtPop3RetrReply*>(sender());
            if (reply == nullptr) {
                QMessageBox::critical(this, "Error", "Failed to fetch message");
                return;
            }
            auto msg = reply->message();
            QHash<QString, QString> headers = msg->extraHeaders();
            QString sender = headers["from"].toUtf8();
            QString subject = headers["subject"].toUtf8();
            QString date = headers["date"].toUtf8();
            QString body = msg->body();

            ReceivedMail mail;
            mail.setFrom(sender);
            mail.setSubject(subject);
            mail.setDate(date);
            mail.setBody(body);
            mails.append(mail);

            ++receivedMailCount;
            if (receivedMailCount == mailCount) {
                displayMails();
            }
            qDebug() << "Received email" << receivedMailCount << ":" << subject;
        }
        break;
    default:
        qDebug() << "Bad return code:" << code;
        QMessageBox::critical(this, "Error", "Failed to fetch message");
        break;
    }
}

void Receiving::handleDele(int code) {
    if (code != QxtPop3Reply::Ok) {
        qDebug() << "Bad return code:" << code;
        QMessageBox::critical(this, "Error", "Failed to delete message");
    }
}

void Receiving::displayMails() {
    ui->mailTable->setRowCount(mails.count());
    for (int i = 0; i < mails.count(); ++i) {
        QTableWidgetItem* item;
        auto mail = mails[i];

        item = new QTableWidgetItem(mail.getFrom(), 0);
        item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        ui->mailTable->setItem(i, 0, item);

        item = new QTableWidgetItem(mail.getSubject(), 1);
        item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        ui->mailTable->setItem(i, 1, item);

        item = new QTableWidgetItem(mail.getBody(), 2);
        item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        ui->mailTable->setItem(i, 2, item);

        item = new QTableWidgetItem(mail.getDate(), 3);
        item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        ui->mailTable->setItem(i, 3, item);
    }
}

void Receiving::onSSLError() {
    QMessageBox::critical(this, "Error", "SSL error");
}

void Receiving::onAuthError() {
    QMessageBox::critical(this, "Error", "POP3 authentication error");
}

void Receiving::onConnectError() {
    QMessageBox::critical(this, "Error", "Cannot connect to the server");
}

void Receiving::setUser(user* use) {
    this->use = use;
}
