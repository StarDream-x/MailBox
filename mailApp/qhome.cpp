/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @author Wang Haonan (Student-ID:2020302191718)
* @date 2022-11-29
*/
#include "qhome.h"
#include<QStyleOption>
#include<QPainter>

Qhome::Qhome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qhome)
{
    ui->setupUi(this);
    draft = new Draft();
    connect(ui->logoutButtton,SIGNAL(clicked()),this,SLOT(logoutHandler()));
    connect(ui->writeButton,SIGNAL(clicked()),this,SLOT(writeHandler()));
    connect(ui->receiveButton,SIGNAL(clicked()),this,SLOT(receiveHandler()));
}

Qhome::~Qhome()
{
    delete draft;
    delete ui;
}

void Qhome::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Qhome::logoutHandler(){
    this->close();
    closed();
}

void Qhome::writeHandler(){
    this->hide();
    Qsend *send = new Qsend;
    send->setUser(this->use);
    send->setDraft(this->draft);
    send->show();
    connect(send,SIGNAL(closed()),this,SLOT(showThis()));
}

void Qhome::receiveHandler() {
    this->hide();
    Receiving *receiving = new Receiving();
    receiving->setUser(this->use);
    receiving->show();
    connect(receiving,SIGNAL(closed()),this,SLOT(showThis()));
    receiving->doConnect();
}

void Qhome::showThis(){
    this->show();
}

void Qhome::setUser(user *use){
    this->use=use;
}
