#ifndef MYSMTP_H
#define MYSMTP_H
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#include <QString>
#include <QDebug>
//#define PORT 25
#define BufferSize 1024
#define Ready "220"
#define OK "250"
#define WaitForInput "334"
#define AuthSuccessfully "235"
#define StartToSend "354"
#define Bye "221"
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
    void CheckResponseCode(QString NormalCode);
    void CloseSocket(SOCKET s);
    QString DomineName;
    QString Base64Encode(QString s);
    void Auth();
    void SendEmail(QString TargetAccount,QString Subject,QString Text);
private:
    static const char Base64EncodeMap[64];
    int Port;
    int SmtpError;
    QString Account;
    QString PassWord;
    SOCKET Client;
};


#endif // MYSMTP_H
