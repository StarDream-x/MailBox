/**
 * @brief A Wrapped Exception Class For QT
 *
 * @author Yuan ChengBo (Student-ID:2020302111253)
 *
 */

#ifndef ERROR_H
#define ERROR_H
#include <QDebug>
using namespace std;

class Error : public std::exception
{
protected:
    QString problem;
    QString reason;

public:
    Error(QString error_name="", QString error_reason=""){
        problem = error_name;
        reason = error_reason;
    }
    ~Error() throw() {}
    const char* what() const throw(){
        QString message;
        message = "Exception: " + problem + ": " + reason;
        return message.toLatin1().data();
    }
};

#endif // ERROR_H
