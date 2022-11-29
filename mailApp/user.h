/**
* @projectName UIDesign
* @brief Introduction
* @author WangXinzhe (Student-ID:2020302142180)
* @date 2022-11-29
*/
#ifndef USER_H
#define USER_H

#include <QString>

class user
{
public:
    user();
    ~user();
    void setName(QString name);
    QString getName();
    void setPassword(QString password);
    QString getPassword();

private:
    QString name;
    QString password;
};

#endif // USER_H
