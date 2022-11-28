#include "MySmtp.h"
#include "ui/mainform.h"

#include <QApplication>

void test_smtp(QString username, QString password) {
    MySmtp smtp("stardream_x@126.com","VDEVVVHEOHOALASB");
    smtp.Auth();
//       smtp.AttachmentArray[0]="D:\\dzf.rar";
//       smtp.AttachmentArray[1]="D:\\dzf.xlsx";
//       smtp.AttachmentArray[2]="D:\\dzf.xls";
    smtp.SendEmail("2020302142180@whu.edu.cn","test","find Version Controller-测试中文");
    qDebug()<<smtp.ErrorNum;
}

void test_pop3() {
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
    QString password = "qwq";
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
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainForm main_form;
    main_form.show();
    return app.exec();
}
