/**
 * @file MySmpt.h
 * @brief A Brief Smtp Client(support mime)
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2022/11/12     20:00
 *
 */
#ifndef MYSMTP_H
#define MYSMTP_H
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#include <QString>
#include <QDebug>
#include <QFile>
#include <QFileDevice>
#include <QFileInfo>
#define BufferSize 65535
#define MaxNumOfAttachment 10
#define Ready "220"
#define OK "250"
#define WaitForInput "334"
#define AuthSuccessfully "235"
#define AuthFailed "535"
#define UserNotFound "550"
#define StartToSend "354"
#define Bye "221"


/**
 * @brief The MySmtp class
 * @example
 * MySmtp smtp("sss@126.com","password");
 * smtp.Auth();函数调用后 ErrorNum=0 正常 2 账号或密码错误 3 网络不稳定等其他原因导致的错误
 * MySmtp smtp("aaa@whu.edu.cn","password");函数调用后 ErrorNum=0 正常  1 用户不存在 3 网络不稳定等其他原因导致的错误
 *                                                                     4 文件不存在  5 无法打开文件
 * smtp.AttachmentArray[0]="D:\\dzf.rar";
 * smtp.AttachmentArray[1]="D:\\dzf.xlsx";
 * smtp.AttachmentArray[2]="D:\\dzf.xls";//没有附件不用写,附件总大小不能太大，最多支持10个附件(最多个数可自己改)
 * smtp.SendEmail("sss@163.com","test","test");
 * qDebug()<<smtp.ErrorNum;
 */
class MySmtp
{
public:
    MySmtp(QString Account,QString PassWord);
    ~MySmtp();
    void InitWSA();
    void CloseWSA();
    SOCKET CreateClientSocket();
    SOCKET ConnectToServer();
    QString GetDomineName();
    QString ReceiveResponse();
    void SendMessage(QString message);
    bool CheckResponseCode(QString NormalCode);
    void CloseSocket(SOCKET s);
    QString DomineName;
    QString Base64Encode(QString s);
    QString Base64Encode(QByteArray b);
    void Auth();
    void SendEmail(QString TargetAccount,QString Subject,QString Text);
    int ErrorNum;
    QString ErrorResponseCode;
    QString AttachmentArray[MaxNumOfAttachment];
    void AddAttachment();
private:
    static const char Base64EncodeMap[64];
    static const QMap<QString,QString> SuffixToType;
    int Port;
    int SmtpError;
    QString Account;
    QString PassWord;
    SOCKET Client;

};


#endif // MYSMTP_H
