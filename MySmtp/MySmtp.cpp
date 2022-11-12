/**
 * @file MySmpt.cpp
 * @brief A Brief Smtp Client
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2022/11/12     20:00
 *
 */

#include"MySmtp.h"
const char MySmtp::Base64EncodeMap[64]={'A','B','C','D','E','F','G','H','I','J','K','L',
                                     'M','N','O','P','Q','R','S','T','U','V','W','X',
                                     'Y','Z','a','b','c','d','e','f','g','h','i','j',
                                     'k','l','m','n','o','p','q','r','s','t','u','v',
                                     'w','x','y','z','0','1','2','3','4','5','6','7',
                                     '8','9','+','/'};

/**
 * @brief 构造函数
 * @param Account 账号
 * @param PassWord 授权码(不是密码，需要去对应服务器申请smtp授权码)
 */
MySmtp::MySmtp(QString Account,QString PassWord)
{
    this->Account = Account;
    this->PassWord=PassWord;
    this->Port=25;
    this->ErrorNum=0;
    InitWSA();
    this->Client=CreateClientSocket();
}


/**
 * @brief 析构函数 关闭socket
 */
MySmtp::~MySmtp()
{
    CloseSocket(Client);
    CloseWSA();
}


/**
 * @brief 初始化WSA
 */
void MySmtp::InitWSA() {
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata)) {
        qDebug()<<"WSAStartup failed code:"<< WSAGetLastError();
        return;
    }
    return;
}


/**
 * @brief base64编码
 */
QString MySmtp::Base64Encode(QString s){
    if(s==NULL){
        return NULL;
    }
    UINT32 len=s.size();
    UINT32 i;
    QString res="";
    for(i=0;i+3<=len;i+=3){
        res.append(Base64EncodeMap[(s[i].toLatin1()>>2)&0x3f]);
        res.append(Base64EncodeMap[((s[i].toLatin1()<<4)&0x30)|((s[i+1].toLatin1()>>4)&0x0f)]);
        res.append(Base64EncodeMap[((s[i+1].toLatin1()<<2)&0x3c)|((s[i+2].toLatin1()>>6)&0x03)]);
        res.append(Base64EncodeMap[s[i+2].toLatin1()&0x3f]);
    }
    if(i<len){
        if(len-i==1){
            res.append(Base64EncodeMap[(s[i].toLatin1()>>2)&0x3f]);
            res.append(Base64EncodeMap[(s[i].toLatin1()<<4)&0x30]);
            res.append('=');
            res.append("=");
        }
        else{
            res.append(Base64EncodeMap[(s[i].toLatin1()>>2)&0x3c]);
            res.append(Base64EncodeMap[((s[i].toLatin1()<<4)&0x30)|((s[i+1].toLatin1()>>4)&0x0f)]);
            res.append(Base64EncodeMap[(s[i+1].toLatin1()<<2)&0x3c]);
            res.append("=");
        }
    }


  return res;
}


/**
 * @brief 创建客户端socket
 */
SOCKET MySmtp::CreateClientSocket() {
    SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client == INVALID_SOCKET) {
        qDebug()<<"SOCKET failed code:"<<WSAGetLastError();
        return INVALID_SOCKET;
    } 
    return client;
}


/**
 * @brief 通过账号获取对应服务器的域名
 * @return example:smtp.qq.com
 */
QString MySmtp::GetDomineName() {
    QString temp = Account;
    QString EmailType;
    DomineName="smtp.";
    int first = temp.indexOf("@");
    EmailType = temp.mid(first + 1, temp.size()- first - 1);
    DomineName += EmailType;
    qDebug()<<"Domine name:"<<DomineName;
    return DomineName;

}


/**
 * @brief 将创建的socket与对应服务器建立连接
 */
SOCKET MySmtp::ConnectToServer() {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(Port);
    QString temp = GetDomineName();
    struct hostent* host = gethostbyname(temp.toStdString().c_str());
    if (!host) {
        qDebug()<<"Get IP address error!";
        ErrorNum=1;
        return false;
    }
    const char* ip = inet_ntoa(*(struct in_addr*)host->h_addr_list[0]);
    qDebug()<<"server ip:"<<ip;
    addr.sin_addr.S_un.S_addr = inet_addr(ip);
    if (connect(Client, (SOCKADDR*)&addr, sizeof(addr))== SOCKET_ERROR) {
        qDebug()<<"connect failed code:"<<WSAGetLastError();
        return false;
    }
    return Client;

}


/**
 * @brief 接受服务器响应
 */
QString MySmtp::ReceiveResponse(){

    char RecvBuf[BufferSize];
    memset(RecvBuf,0,sizeof(RecvBuf));

    if(recv(Client,RecvBuf,BufferSize,0)==SOCKET_ERROR){
         qDebug()<<"recv failed code:"<<WSAGetLastError();
         return NULL;
    }

    qDebug()<<"recv:"<< RecvBuf;
    QString str(RecvBuf);
    return str;

}


/**
 * @brief 检查响应码是否正确
 * @param NormalCode 正确的响应码
 */
bool MySmtp::CheckResponseCode(QString NormalCode){
    QString Response=ReceiveResponse();
    if(!DomineName.compare("smtp.whu.edu.cn")&&NormalCode==Ready){
        char RecvBuf[BufferSize];
        recv(Client,RecvBuf,BufferSize,0);
        QString str(RecvBuf);
        Response.append(str);
        qDebug()<<"recv:"<< Response;
    }

    QString ResponseCode;
    ResponseCode=Response.left(3);
    if(ResponseCode.compare(NormalCode)){
        ErrorResponseCode=ResponseCode;
        qDebug()<<"Error code:"<<ResponseCode;
        return false;
    }
    return true;
}


/**
 * @brief 客户端向服务器发送信息
 */
void MySmtp::SendMessage(QString message){
    qDebug()<<"send:"<<message;
    if(send(Client,message.toStdString().c_str(),message.size(),0)<0){
        qDebug()<<"send failed code:"<<WSAGetLastError();
        return;
    }
    return;
}


/**
 * @brief 认证阶段，对账号和密码进行认证
 */
void MySmtp::Auth(){
    ConnectToServer();
    if(!CheckResponseCode(Ready)&&!ErrorNum){
        ErrorNum=3;
    }
    SendMessage("EHLO "+DomineName+"\r\n");
    if(!CheckResponseCode(OK)&&!ErrorNum){
        ErrorNum=3;
    }

    SendMessage("AUTH LOGIN\r\n");
    if(!CheckResponseCode(WaitForInput)&&!ErrorNum){
        ErrorNum=3;
    }
    SendMessage(Base64Encode(Account)+"\r\n");
    if(!CheckResponseCode(WaitForInput)&&!ErrorNum){
        ErrorNum=3;
    }
    SendMessage(Base64Encode(PassWord)+"\r\n");
    if(!CheckResponseCode(AuthSuccessfully)&&!ErrorNum&&!ErrorResponseCode.compare(AuthFailed)){
        ErrorNum=2;
    }
}


/**
 * @brief 写邮件阶段
 * @param TargetAccount 对方账号
 * @param Subject 邮件主题
 * @param Text 邮件内容
 */
void MySmtp::SendEmail(QString TargetAccount,QString Subject,QString Text){
    SendMessage("mail from: <"+Account+">"+"\r\n");
    if(!CheckResponseCode(OK)&&!ErrorResponseCode.compare(UserNotFound)){
        ErrorNum=1;
    }
    SendMessage("rcpt to: <"+TargetAccount+">"+"\r\n");
    if(!CheckResponseCode(OK)&&!ErrorResponseCode.compare(UserNotFound)){
        ErrorNum=1;
    }
    SendMessage("DATA\r\n");

    if(!CheckResponseCode(StartToSend)&&!ErrorNum){
        ErrorNum=3;
    }
    SendMessage("From: "+Account+"\r\n");
    SendMessage("To: "+TargetAccount+"\r\n");
    SendMessage("Subject: "+Subject+"\r\n");
    SendMessage("\r\n"+Text+"\r\n.\r\n");
    if(!CheckResponseCode(OK)&&!ErrorNum){
        ErrorNum=3;
    }
    SendMessage("QUIT\r\n");
    if(!CheckResponseCode(Bye)&&!ErrorNum){
        ErrorNum=3;
    }
}


/**
 * @brief 关闭socket
 */
void MySmtp::CloseSocket(SOCKET s)
{
    if (closesocket(s) == SOCKET_ERROR) {
        qDebug()<<"closesocket failed code:"<<WSAGetLastError();
        return;
    }
    return;
}

/**
 * @brief 关闭WSA
 */
void MySmtp::CloseWSA() {
    if (WSACleanup()) {
        qDebug()<<"WSACleanup failed code:"<<WSAGetLastError();
        return;
    }
    return;
}

