/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @author Wang Haonan (Student-ID:2020302191718)
* @date 2022-11-29
*/
#ifndef QHOME_H
#define QHOME_H

#include <QWidget>
#include "ui_qhome.h"
#include "qsend.h"
#include "receiving.h"
#include "user.h"
#include "draft.h"

namespace Ui {
class Qhome;
}

class Qhome : public QWidget
{
    Q_OBJECT

public:
    explicit Qhome(QWidget *parent = nullptr);
    ~Qhome();
    void paintEvent(QPaintEvent *e);
    void setUser(user *use);

private:
    Ui::Qhome *ui;
    user *use;
    Draft *draft;

private slots:
    void logoutHandler();
    void writeHandler();
    void receiveHandler();
    void showThis();

signals:
    void closed();
};

#endif // QHOME_H
