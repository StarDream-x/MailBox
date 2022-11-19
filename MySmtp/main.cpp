#include "mainwindow.h"
#include "MySmtp.h"
#include <QApplication>
#include<QDateTime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /**
     * @example
 *     MySmtp smtp("sss@126.com","password");
       smtp.Auth();
       smtp.AttachmentArray[0]="D:\\dzf.rar";
       smtp.AttachmentArray[1]="D:\\dzf.xlsx";
       smtp.AttachmentArray[2]="D:\\dzf.xls";//
       smtp.SendEmail("sss@163.com","test","test");
       qDebug()<<smtp.ErrorNum;
     */
      return a.exec();
}

