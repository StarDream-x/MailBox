/**
 * @brief A Brief Pop3 Client
 *
 * @author Yuan ChengBo (Student-ID:2020302111253)
 *
 */

#ifndef CLIENTPOP_H
#define CLIENTPOP_H

#include <QObject>
#include <QDebug>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "config.h"
#include "error.h"
#include "clientsocket.h"

using namespace std;

class ServerResponse{  // The Result of Query by Pop Client

public:
    bool status;   // 1 for +OK ; 0 for -ERR
    QString status_message;
    QList<QString> data;  // recieved data organized by line

    // display the response
    void display() const{
        cout<<"status="<<status<<endl;
        cout<<"status_message="<<status_message.toStdString()<<endl;
        int size = data.size();
        printf("size=%d\n",size);
        for(int i=0;i<size;++i){
            cout<<data[i].toStdString()<<endl;
        }
    }

    // clear all data of this
    void clear(){
        data.clear();
        status = 0;
        status_message = "";
    }
};

class ClientPop : public QObject{
    // Note: Update the configuration file(config.h) first to use this Pop3 Client.
    Q_OBJECT

private:
    ClientSocket* socket;

public:
    // Initialization a pop client with address * port
    ClientPop(const QString & address, const int & port=DEFAULT_PORT);
    ~ClientPop();

    // authenticate with the mail server by the username & password (correspond to USER & PASS)
    void authenticate(const QString & username, const QString & password);

    // get the message list from the mail server (correspond to LIST)
    ServerResponse get_message_list();

    // get a specific message (with message_id) from the mail server (correspod to RETR)
    ServerResponse get_message(int message_id);

private:
    void send_command(const QString & command);
    void receive_response(ServerResponse & response);
    void get_data(ServerResponse & response);
    void open(const QString & address, const int & port);
    void close();

};

#endif // CLIENTPOP_H
