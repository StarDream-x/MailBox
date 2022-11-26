/**
 * @brief User Entity
 *
 * @author Wang Xinzhe (Student-ID:2020302142180)
 *
 */

#ifndef USER_H
#define USER_H

#include<QString>

class User
{
private:
    QString uname;
    QString upassword;
    bool status;
public:
    User();

    User(QString uname,QString upassword="",bool status=false);

    //get/set method
    QString getUname();
    void setUname(QString uname);
    QString getUpassword();
    void setUpassword(QString upassword);
    bool getStatus(){return status;}
    void setStatus(bool status){this->status=status;}

    //connect
    bool testConnect();

};

#endif // USER_H
