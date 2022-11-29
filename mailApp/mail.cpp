/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @date 2022-11-29
*/
#include "mail.h"

Mail::Mail()
{
    this->from="";
    this->to="";
    this->subject="";
    this->body="";
}

void Mail::setFrom(QString from){
    this->from=from;
}

QString Mail::getFrom(){
    return this->from;
}

void Mail::setTo(QString to){
    this->to=to;
}

QString Mail::getTo(){
    return this->to;
}

void Mail::setSubject(QString subject){
    this->subject=subject;
}

QString Mail::getSubject(){
    return this->subject;
}

void Mail::setBody(QString body){
    this->body=body;
}

QString Mail::getBody(){
    return this->body;
}
