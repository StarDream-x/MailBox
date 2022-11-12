#include "mainwindow.h"
#include "MySmtp.h"
#include <QApplication>
#include<QDateTime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MySmtp smtp("a@whu.edu.cn","password");
    smtp.Auth();
    smtp.SendEmail("729159553@qq.com","test","test"); //对方账号，主题，内容
    qDebug()<<smtp.ErrorNum;

    return a.exec();
}
