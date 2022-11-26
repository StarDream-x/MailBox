/**
 * @brief User Entity
 *
 * @author Wang Xinzhe (Student-ID:2020302142180)
 *
 */

#include "user.h"

User::User(){}

User::User(QString uname,QString upassword,bool status):
uname(uname),upassword(upassword),status(status){}



//get/set method
QString User::getUname(){return this->uname;}
void User::setUname(QString uname){this->uname=uname;}
QString User::getUpassword(){return this->upassword;}
void User::setUpassword(QString upassword){this->upassword=upassword;}

//testConnect
bool User::testConnect(){
//    if(popTest(this)&&smtpTest(this)){
//        this->setStatus(true);
//    }
    return this->getStatus();
}
