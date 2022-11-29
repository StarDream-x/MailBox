/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @author Wang Haonan (Student-ID:2020302191718)
* @date 2022-11-29
*/
#ifndef QSEND_H
#define QSEND_H

#include <QWidget>
#include <ui_qsend.h>
#include "user.h"
#include "MySmtp.h"
#include "mail.h"
#include "draft.h"

namespace Ui {
class Qsend;
}

class Qsend : public QWidget
{
    Q_OBJECT

public:
    explicit Qsend(QWidget *parent = nullptr);
    ~Qsend();
    void paintEvent(QPaintEvent *e);
    void setUser(user *use);
    void setDraft(Draft* draft);

private:
    Ui::Qsend *ui;
    user *use;
    Draft* draft;

private slots:
    void backHandler();
    void sendHandler();
    void draftHandler();

signals:
    void closed();

};

#endif // QSEND_H
