/**
 * @brief A Wrapped Socket Class For QT
 *
 * @author Yuan ChengBo (Student-ID:2020302111253)
 *
 */

#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QTcpSocket>
#include <QObject>
#include <QDebug>

#include "config.h"
#include "error.h"

class ClientSocket : public QObject
{
    Q_OBJECT;

private:
    QTcpSocket* session;
    QString address;
    int port;
    void open();   // open the socket session
    void close();  // close the socket session

private slots:
    void socket_connected();   // verified the connection between server
    void socket_error(QAbstractSocket::SocketError);  // handle the error of socket

public:
    int timeout = 1000*SOCKET_READ_TIMEOUT;
    ClientSocket(const QString& address, const int& port=DEFAULT_PORT);
    ~ClientSocket();

    void socket_read_ready();  // verified the reading environment is ready.

    // Return -1 if an error occured
    //         0 if no more data is available for reading
    //         otherwise the size of byte read by buffer
    ssize_t read(char* buffer, size_t size);// read maximum size bytes from socket buffer
    ssize_t read_line(char* buffer, size_t size); // read one line(end with \n) from socket buffer
    ssize_t read_all(char* buffer);  // read all content of socket buffer

    // Return -1 if an error occured
    //        otherwise the size of byte write to buffer
    ssize_t write(char* const & content, size_t size); // write the content to the socket buffer
};

#endif // CLIENTSOCKET_H
