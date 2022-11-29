/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @date 2022-11-29
*/
#ifndef MAIL_H
#define MAIL_H
#include <QString>

class Mail
{
public:
    Mail();
    void setFrom(QString from);
    QString getFrom();
    void setTo(QString to);
    QString getTo();
    void setSubject(QString subject);
    QString getSubject();
    void setBody(QString body);
    QString getBody();

private:
    QString from;
    QString to;
    QString subject;
    QString body;
};

#endif // MAIL_H
