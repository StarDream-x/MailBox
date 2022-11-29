/**
* @author Wang Haonan (Student-ID:2020302191718)
* @date 2022-11-29
*/

#include "draft.h"

Draft::Draft() {
}

Draft::~Draft() {
}

QString Draft::get_receiver() const {
    return receiver;
}

QString Draft::get_subject() const {
    return subject;
}

QString Draft::get_body() const {
    return body;
}

void Draft::set_receiver(const QString& receiver) {
    this->receiver = receiver;
}

void Draft::set_subject(const QString& subject) {
    this->subject = subject;
}

void Draft::set_body(const QString& body) {
    this->body = body;
}

void Draft::clear() {
    this->receiver = QString();
    this->subject = QString();
    this->body = QString();
}
