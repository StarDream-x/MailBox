/**
 * @brief Unit Test For Pop3 Client
 *
 * @author Yuan ChengBo (Student-ID:2020302111253)
 *
 */

#include <QtCore/QCoreApplication>
#include <QNetworkInterface>
#include <QDnsLookup>
#include <QTcpSocket>
#include <QHostInfo>
#include <QElapsedTimer>
#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "config.h"
#include "clientpop.h"
#include "clientsocket.h"

using namespace std;

QString get_local_ipv4()
{
    QList<QHostAddress> list=QNetworkInterface::allAddresses();
    foreach(QHostAddress address,list)
    {
        if(address.protocol()==QAbstractSocket::IPv4Protocol)
        {
            return address.toString();
        }
    }
    return "";
}

void search_dns_ipv4(QString server_name){
    cout<<"server_Name="<<server_name.toStdString()<<endl;
    QDnsLookup * dns = new QDnsLookup();
    dns->setNameserver(QHostAddress(QString("202.103.0.68")));
    QDnsLookup::connect(dns, &QDnsLookup::finished,[dns]
    {
        qDebug()<<"finished";
        if (dns->error() != QDnsLookup::NoError)
        {
            qWarning("DNS查找失败");
            dns->deleteLater();
            return;
        }

        foreach (auto &record , dns->hostAddressRecords())
        {
            qDebug()<<record.name()<<" "<<record.value();
        }

        dns->deleteLater();
    });

    dns->setType(QDnsLookup::A);
    dns->setName(server_name);
    dns->lookup();
    QDnsLookup::disconnect(dns, nullptr, nullptr, nullptr);
}

//QString get_dns_ipv4(QString server_name){
//    cout<<"server_Name="<<server_name.toStdString()<<endl;
//    QDnsLookup* dns = new QDnsLookup();
//    QElapsedTimer timer;
//    dns->setNameserver(QHostAddress(QString("202.103.0.68")));
//    dns->setType(QDnsLookup::A);
//    dns->setName(server_name);
//    cout<<dns->nameserver().toIPv4Address()<<endl;
//    cout<<"!"<<endl;
//    timer.start();
//    dns->lookup();
//    while(!dns->isFinished() && timer.elapsed()<10000);
//    if(!dns->isFinished()){
//        QList<QDnsHostAddressRecord> ql = dns->hostAddressRecords();
//        return QString(ql.first().value().toIPv4Address());
//        return "FAILED";
//    }
//    else{
//        QList<QDnsHostAddressRecord> ql = dns->hostAddressRecords();
//        return QString(ql.first().value().toIPv4Address());
//    }
//}

int main(int argc, char *argv[]){
    QCoreApplication my_process(argc, argv);

//    search_dns_ipv4("www.baidu.com");

//    QString server_ip;
//    server_ip = get_dns_ipv4("www.baidu.com");
//    cout<<"ip_address="<<server_ip.toStdString()<<endl;

    //qq mail
//    QString server_ip="14.18.175.202";

    //whu mail
//    QString server_ip="202.114.64.84";

    //126 mail
    QString server_ip="123.126.96.209";

    ClientSocket sock(server_ip, DEFAULT_PORT);
    cout<<"(1) socket connection successed."<<endl;

    ClientPop pop(server_ip, DEFAULT_PORT);
    cout<<"(2) pop3 connection succeeed."<<endl;

    QString username = "stardream_x@126.com";
    QString password = "VDEVVVHEOHOALASB";
    cout<<"username="<<username.toStdString()<<endl;
    cout<<"password="<<password.toStdString()<<endl;

    pop.authenticate(username, password);
    cout<<"(3) pop3 authenticate succeed."<<endl;

    ServerResponse response;

    response = pop.get_message_list();
    response.display();
    cout<<"(4) pop3 get_message_list succeed."<<endl;

    int retr_id = 7;
    response = pop.get_message(retr_id);
    response.display();
    cout<<"(5) pop3 get_message(1) succeed."<<endl;

    return 0;
}
