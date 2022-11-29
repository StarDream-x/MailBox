/**
* @author Wang Haonan (Student-ID:2020302191718)
* @date 2022-11-29
*/

#ifndef DRAFT_H
#define DRAFT_H

#include <QString>
#include <QList>


class Draft {
private:
    QString receiver;
    QString subject;
    QString body;

public:
    explicit Draft();
    ~Draft();
    QString get_receiver() const;
    QString get_subject() const;
    QString get_body() const;
    void set_receiver(const QString& receiver);
    void set_subject(const QString& subject);
    void set_body(const QString& body);
    void clear();
};

#endif // DRAFT_H
