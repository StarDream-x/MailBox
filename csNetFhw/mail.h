/**
 * @brief Mail Entity
 *
 * @author Wang Xinzhe (Student-ID:2020302142180)
 *
 */

#ifndef MAIL_H
#define MAIL_H

#include<QString>

class Mail
{
private:
    QString from;
    QString to;
    QString title;
    QString content;
    QString date;

public:
    Mail();
    Mail(QString from,QString to,QString title,QString content="",QString date="");

    //get/set method
    QString getFrom();
    void setFrom(QString from);
    QString getTo();
    void setTo(QString to);
    QString getTitle();
    void setTitle(QString title);
    QString getContent();
    void setContent(QString content);
    QString getDate();
    void setDate(QString date);

    //post mail
    void postMail();

};

#endif // MAIL_H
