/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @date 2022-11-29
*/
#ifndef HOME_H
#define HOME_H

//#include "ui_mainwindow.h"
#include <QWidget>
#include "ui_home.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Home; }
QT_END_NAMESPACE

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();
    void paintEvent(QPaintEvent *e);

private:
    Ui::Home *ui;

private slots:
    void logoutHandler();
};
#endif // LOGIN_H
