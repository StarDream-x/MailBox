#include"MySmtp.h"
const char MySmtp::Base64EncodeMap[64]={'A','B','C','D','E','F','G','H','I','J','K','L',
                                     'M','N','O','P','Q','R','S','T','U','V','W','X',
                                     'Y','Z','a','b','c','d','e','f','g','h','i','j',
                                     'k','l','m','n','o','p','q','r','s','t','u','v',
                                     'w','x','y','z','0','1','2','3','4','5','6','7',
                                     '8','9','+','/'};

MySmtp::MySmtp(QString Account,QString PassWord)
{
    this->Account = Account;
    this->PassWord=PassWord;
    this->Port=25;
    InitWSA();
    this->Client=CreateClientSocket();
}

MySmtp::~MySmtp()
{
    CloseSocket(Client);
    CloseWSA();
}
//启动Winsock DLL
void MySmtp::InitWSA() {
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata)) {
        qDebug()<<"WSAStartup failed code:"<< WSAGetLastError();
        return;
    }
    return;
}
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
//关闭Winsock DLL
void MySmtp::CloseWSA() {
    if (WSACleanup()) {
        qDebug()<<"WSACleanup failed code:"<<WSAGetLastError();
        return;
    }
    return;
}
/*
  创建SOCKET
  输出一个未连接服务器的socket
*/
SOCKET MySmtp::CreateClientSocket() {
    SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client == INVALID_SOCKET) {
        qDebug()<<"SOCKET failed code:"<<WSAGetLastError();
        return INVALID_SOCKET;
    } 
    return client;

}
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

//与服务器建立TCP连接
SOCKET MySmtp::ConnectToServer() {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(Port);
    QString temp = GetDomineName();
    struct hostent* host = gethostbyname(temp.toStdString().c_str());
    if (!host) {
        qDebug()<<"Get IP address error!";
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
//接收服务器消息
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
void MySmtp::SendMessage(QString message){
    qDebug()<<"send:"<<message;
    if(send(Client,message.toStdString().c_str(),message.size(),0)<0){
        qDebug()<<"send failed code:"<<WSAGetLastError();
        return;
    }
    return;
}

void MySmtp::CheckResponseCode(QString NormalCode){
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
        qDebug()<<"Error code:"<<ResponseCode;
        return;
    }
}
void MySmtp::Auth(){
    ConnectToServer();
    CheckResponseCode(Ready);
    SendMessage("EHLO "+DomineName+"\r\n");
    CheckResponseCode(OK);
//    smtp.SendMessage(client,"STARTTLS\r\n");
//    smtp.CheckResponseCode(client,Ready);
    SendMessage("AUTH LOGIN\r\n");
    CheckResponseCode(WaitForInput);
    SendMessage(Base64Encode(Account)+"\r\n");
    CheckResponseCode(WaitForInput);
    SendMessage(Base64Encode(PassWord)+"\r\n");
    CheckResponseCode(AuthSuccessfully);
}
void MySmtp::SendEmail(QString TargetAccount,QString Subject,QString Text){
    SendMessage("mail from: <"+Account+">"+"\r\n");
    CheckResponseCode(OK);
    SendMessage("rcpt to: <"+TargetAccount+">"+"\r\n");
    CheckResponseCode(OK);
    SendMessage("DATA\r\n");
    CheckResponseCode(StartToSend);
    SendMessage("From: "+Account+"\r\n");
    SendMessage("To: "+TargetAccount+"\r\n");
    SendMessage("Subject: "+Subject+"\r\n");
    SendMessage("\r\n"+Text+"\r\n.\r\n");
    CheckResponseCode(OK);
    SendMessage("QUIT\r\n");
    CheckResponseCode(Bye);
}
//关闭socket
void MySmtp::CloseSocket(SOCKET s)
{
    if (closesocket(s) == SOCKET_ERROR) {
        qDebug()<<"closesocket failed code:"<<WSAGetLastError();
        return;
    }
    return;
}


