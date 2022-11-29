/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @date 2022-11-29
*/
#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Ceil);
    QApplication a(argc, argv);
    Index *w = new Index;
    w->show();
    return a.exec();
}
