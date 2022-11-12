/**
 * @file MySmpt.h
 * @brief A Brief Smtp Client
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

#define BufferSize 65535
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
 * example:
 *  MySmtp smtp("aaa@whu.edu.cn","password");
 *  smtp.Auth(); 函数调用后 ErrorNum=0 正常 2 账号或密码错误 3 网络不稳定等其他原因导致的错误
 *  smtp.SendEmail("729159553@qq.com","test","test"); 函数调用后 ErrorNum=0 正常  1 用户不存在 3 网络不稳定等其他原因导致的错误
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
    void Auth();
    void SendEmail(QString TargetAccount,QString Subject,QString Text);
    int ErrorNum;
    QString ErrorResponseCode;
private:
    static const char Base64EncodeMap[64];
    int Port;
    int SmtpError;
    QString Account;
    QString PassWord;
    SOCKET Client;

};


#endif // MYSMTP_H
