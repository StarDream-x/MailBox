/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @author Wang Haonan (Student-ID:2020302191718)
* @date 2022-11-29
*/
#include "login.h"
#include "qhome.h"
#include<QStyleOption>
#include<QPainter>
#include <QMessageBox>

Index::Index(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Index)
{
    ui->setupUi(this);
    connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(loginHandler()));
    connect(ui->exitButton,SIGNAL(clicked()),this,SLOT(exitHandler()));
    this->use = new user;
}

Index::~Index()
{
    free(this->use);
    delete ui;
}

void Index::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Index::loginHandler(){
    this->use->setName(ui->account->text());
    this->use->setPassword(ui->password->text());
    MySmtp *smtp = new MySmtp(this->use->getName(),this->use->getPassword());
    smtp->Auth();
    if(smtp->ErrorNum>0) connectFail();
    else connectSuccess();
    delete smtp;
}

void Index::connectFail(){
    QMessageBox::critical(this, "Error", "Login failed");
}

void Index::connectSuccess(){
    this->hide();
    Qhome *home = new Qhome;
    home->setUser(this->use);
    home->show();
    connect(home,SIGNAL(closed()),this,SLOT(showThis()));
}

void Index::showThis(){
    this->show();
}

void Index::exitHandler(){
    this->close();
}
