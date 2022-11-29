/**
* @author Wang Haonan (Student-ID:2020302191718)
* @date 2022-11-29
*/

#include "receivedmail.h"

ReceivedMail::ReceivedMail() {
    this->from = "";
    this->subject = "";
    this->body = "";
}

void ReceivedMail::setFrom(QString from) {
    this->from = from;
}

QString ReceivedMail::getFrom() {
    return this->from;
}

void ReceivedMail::setSubject(QString subject) {
    this->subject = subject;
}

QString ReceivedMail::getSubject() {
    return this->subject;
}

void ReceivedMail::setBody(QString body) {
    this->body = body;
}

QString ReceivedMail::getBody() {
    return this->body;
}

void ReceivedMail::setDate(QString date) {
    this->date = date;
}

QString ReceivedMail::getDate() {
    return this->date;
}
