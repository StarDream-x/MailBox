/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @date 2022-11-29
*/
#ifndef LOGIN_H
#define LOGIN_H

//#include "ui_mainwindow.h"
#include <QWidget>
#include "ui_login.h"
#include "user.h"
#include "MySmtp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Index; }
QT_END_NAMESPACE

class Index : public QWidget
{
    Q_OBJECT

public:
    explicit Index(QWidget *parent = nullptr);
    ~Index();
    void paintEvent(QPaintEvent *e);
    void connectFail();
    void connectSuccess();

private:
    Ui::Index *ui;
    user *use;

private slots:
    void loginHandler();
    void showThis();
    void exitHandler();
};
#endif // LOGIN_H
