/**
 * @brief A Brief Pop3 Client
 *
 * @author Yuan ChengBo (Student-ID:2020302111253)
 *
 */

#include <algorithm>
#include <cstdio>
#include <cstdlib>

#include "clientpop.h"

ClientPop::ClientPop(const QString & address, const int & port){
    this->open(address, port);
}

ClientPop::~ClientPop(){
    this->close();
}

void ClientPop::open(const QString & address, const int & port){
    socket = new ClientSocket(address, port);
    ServerResponse welcome;
    this->receive_response(welcome);
    if(!welcome.status){
        throw Error("Connection refused", welcome.status_message);
    }
}

void ClientPop::close(){
    free(this->socket);
}

void ClientPop::send_command(const QString & command){
    QString command_send = command;
    command_send.append("\r\n");
    char* ch = command_send.toLatin1().data();
    int size = command_send.toLatin1().size();
    this->socket->write(ch, size);
}

void ClientPop::receive_response(ServerResponse & response){
    char buffer[MAX_BUFFER_SIZE];
    this->socket->socket_read_ready();
    this->socket->read_line(buffer, MAX_BUFFER_SIZE);
//    printf("BUFFER_BEGIN:\n");
//    int l=strlen(buffer);
//    printf("length=%d\n",l);
//    for(int i=0;i<l;++i) printf("%c",buffer[i]);
//    printf("\nBUFFER_END\n");
    if(buffer[0] == '+'){
        response.status = 1;
        response.status_message = QString(buffer).remove(0, 4);
    }
    else{
        response.status = 0;
        response.status_message = QString(buffer).remove(0, 5);
    }
}

void ClientPop::get_data(ServerResponse &response){
    char buffer[MAX_BUFFER_SIZE];
    ssize_t size;
    QString message_line;
    response.data.clear();
    while(1){
        memset(buffer, 0, sizeof(buffer));
        size = this->socket->read_line(buffer, MAX_BUFFER_SIZE);
        int l=strlen(buffer);
        printf("l=%d\n",l);
        if(size<3 || (buffer[0]=='.'&&size==3)){
            break;
        }
        message_line = QString(buffer);
        if(buffer[0]=='.') message_line.remove(0, 1);
        response.data.push_back(message_line);
    }
}

void ClientPop::authenticate(const QString & username, const QString & password){
    ServerResponse response;
    this->send_command("USER "+username);
    this->receive_response(response);
    if(!response.status){
        throw Error("Authentication failed", response.status_message);
    }
    this->send_command("PASS "+password);
    this->receive_response(response);
    if(!response.status){
        throw Error("Authentication failed", response.status_message);
    }
}

ServerResponse ClientPop::get_message_list(){
    ServerResponse response;
    this->send_command("LIST");
    this->receive_response(response);
    if(!response.status){
        throw Error("Unable to retrieve message list", response.status_message);
    }
    this->get_data(response);
    return response;
}

ServerResponse ClientPop::get_message(int message_id){
    ServerResponse response;
    this->send_command(QString("RETR ").append(QString::number(message_id)));
    this->receive_response(response);
    if(!response.status){
        throw Error("Unable to retrieve requested message", response.status_message);
    }
    this->get_data(response);
    return response;
}
