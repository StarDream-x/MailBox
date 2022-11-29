/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @date 2022-11-29
*/
#include "home.h"
#include<QStyleOption>
#include<QPainter>

Home::Home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);
//    connect(ui->logoutButtton, SIGNAL(clicked()), this, SLOT(logoutHandler));
}

Home::~Home()
{
    delete ui;
}

void Home::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

//void Home::logoutHandler(){
//    this->close();
//}


