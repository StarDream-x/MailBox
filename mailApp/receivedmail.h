/**
* @author Wang Haonan (Student-ID:2020302191718)
* @date 2022-11-29
*/

#ifndef RECEIVEDMAIL_H
#define RECEIVEDMAIL_H

#include <qstring.h>


class ReceivedMail
{
public:
    ReceivedMail();
    void setFrom(QString from);
    QString getFrom();
    void setSubject(QString subject);
    QString getSubject();
    void setBody(QString body);
    QString getBody();
    void setDate(QString date);
    QString getDate();

private:
    QString from;
    QString subject;
    QString body;
    QString date;
};

#endif // RECEIVEDMAIL_H
