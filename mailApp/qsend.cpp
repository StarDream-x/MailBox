/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @date 2022-11-29
*/
#include "qsend.h"
#include "ui_qsend.h"
#include<QStyleOption>
#include<QPainter>

Qsend::Qsend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qsend)
{
    ui->setupUi(this);
    connect(ui->backButton,SIGNAL(clicked()),this,SLOT(backHandler()));
    connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(sendHandler()));
}

Qsend::~Qsend()
{
    delete ui;
}

void Qsend::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Qsend::setUser(user *use){
    this->use=use;
}

void Qsend::backHandler(){
    this->close();
    closed();
}

void Qsend::sendHandler(){
    MySmtp *smtp = new MySmtp(this->use->getName(),this->use->getPassword());
    Mail *mail = new Mail();
    mail->setFrom(this->use->getName());
    mail->setTo(ui->to->text());
    mail->setSubject(ui->subject->text());
    mail->setBody(ui->body->toPlainText());
    smtp->Auth();
    smtp->SendEmail(mail->getTo(),mail->getSubject(),mail->getBody());
    bool flag=true;
    if(smtp->ErrorNum>0) flag=false;
    delete smtp;
    delete mail;
    if(flag) backHandler();
}
