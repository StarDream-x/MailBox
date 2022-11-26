#include "mainwindow.h"
#include "MySmtp.h"
#include <QApplication>
#include<QDateTime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//      @example
       MySmtp smtp("stardream_x@126.com","VDEVVVHEOHOALASB");
       smtp.Auth();
//       smtp.AttachmentArray[0]="D:\\dzf.rar";
//       smtp.AttachmentArray[1]="D:\\dzf.xlsx";
//       smtp.AttachmentArray[2]="D:\\dzf.xls";
       smtp.SendEmail("2020302142180@whu.edu.cn","test","find Version Controller-测试中文");
       qDebug()<<smtp.ErrorNum;

      return a.exec();
}

