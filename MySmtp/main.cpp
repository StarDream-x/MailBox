#include "mainwindow.h"
#include "MySmtp.h"
#include <QApplication>
#include<QDateTime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MySmtp smtp("2020302041100@whu.edu.cn","RdicW24DeFYnscpV");
    smtp.Auth();
    smtp.SendEmail("729159553@qq.com","test","test\r\naaaa");


//    smtp.SendMessage("")
    return a.exec();
}
