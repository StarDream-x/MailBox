/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @date 2022-11-29
*/
#include "user.h"

user::user()
{

}

void user::setName(QString name){
    this->name=name;
}

void user::setPassword(QString password){
    this->password=password;
}

QString user::getName(){
    return this->name;
}

QString user::getPassword(){
    return this->password;
}
