/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
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
    connect(ui->logoutButtton,SIGNAL(clicked()),this,SLOT(logoutHandler()));
    connect(ui->writeButton,SIGNAL(clicked()),this,SLOT(writeHandler()));
}

Qhome::~Qhome()
{
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
    send->show();
    connect(send,SIGNAL(closed()),this,SLOT(showThis()));
}

void Qhome::showThis(){
    this->show();
}

void Qhome::setUser(user *use){
    this->use=use;
}
