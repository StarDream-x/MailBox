/**
 * @brief Mail Entity
 *
 * @author Wang Xinzhe (Student-ID:2020302142180)
 *
 */

#include "mail.h"

Mail::Mail(){}

Mail::Mail(QString from,QString to,QString title,QString content,QString date):
from(from),to(to),title(title),content(content),date(date){}


//get/set method
QString Mail::getFrom(){return this->from;}
void Mail::setFrom(QString from){this->from=from;}
QString Mail::getTo(){return this->to;}
void Mail::setTo(QString to){this->to=to;}
QString Mail::getTitle(){return this->title;}
void Mail::setTitle(QString title){this->title=title;}
QString Mail::getContent(){return this->content;}
void Mail::setContent(QString content){this->content=content;}
QString Mail::getDate(){return this->date;}
void Mail::setDate(QString date){this->date=date;}

//post mail
void Mail::postMail(){
    //call smtp
}
