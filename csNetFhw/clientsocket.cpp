/**
 * @brief A Wrapped Socket Class For QT
 *
 * @author Yuan ChengBo (Student-ID:2020302111253)
 *
 */

#include <QCoreApplication>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QObject>
#include <QDebug>
#include <iostream>

#include "clientsocket.h"

using namespace std;

ClientSocket::ClientSocket(const QString& address, const int& port){
    this->address = address;
    this->port = port;
    if(port<0 || port>65535){
        throw Error("Unable to connect", "Illegal port");
    }
    this->open();
}

ClientSocket::~ClientSocket(){
    // produced when a exception is thrown, or at the end of object's life cycle.
    close();
}

void ClientSocket::open(){
    session = new QTcpSocket();
    QObject::connect(session, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socket_error(QAbstractSocket::SocketError)));
    QObject::connect(session, SIGNAL(connected()), this, SLOT(socket_connected()));
    session->connectToHost(this->address, this->port);
    bool op = session->waitForConnected(this->timeout);
    if(!op){
        throw Error("Establish connection error", "Server not responding.");
    }
}

void ClientSocket::close(){
    session->disconnectFromHost();
    QObject::disconnect(session, nullptr, this, nullptr);
    free(session);
}

void ClientSocket::socket_error(QAbstractSocket::SocketError error_enum){
    throw Error("Fail to establish connection with server", session->errorString());
}

void ClientSocket::socket_connected(){
    // RESERVED
    // cout<<"Connected Success"<<endl;
}

void ClientSocket::socket_read_ready(){
    // notice that this function need to be conducted by user
    bool op = session->waitForReadyRead(this->timeout);
    if(!op) {
        throw Error("Recieving error", "Server not responding (connection timed out).");
    }
}

ssize_t ClientSocket::read(char* buffer, size_t size){
    ssize_t state = session->read(buffer, size);
    return state;
}

ssize_t ClientSocket::read_line(char* buffer, size_t size){
    bool op = session->canReadLine();
    if(!op){
        /*
        (TODO): I found that sometimes the content returned by qq mailbox does not
                    end with '\r\n', so I use read_all() to alleviate this problem.
                However, this leads to a security problem, which should be fixed by
                    the later developers.
        */
        return read_all(buffer);
        // throw Error("Recieving error", "Incomplete line occurred.");
    }
    ssize_t state = session->readLine(buffer, size);
    return state;
}

ssize_t ClientSocket::read_all(char* buffer){
    QByteArray buf = session->readAll();
    int buf_size = buf.size();
    memcpy(buffer, buf, buf_size);
    return buf_size;
}

ssize_t ClientSocket::write(char* const & content, size_t size){
    int state = session->write(content, size);
    return state;
}
