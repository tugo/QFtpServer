#ifndef FTPSERVER_H
#define FTPSERVER_H

#include <QObject>

class QTcpServer;

// the ftp server
// listens on a port, and starts a new control
// connection each time it gets connected

class FtpServer : public QObject
{
    Q_OBJECT
public:
    explicit FtpServer(QObject *parent, const QString &rootPath, int port = 21, const QString &userName = QString(), const QString &password = QString());
    bool isListening();

signals:
    
private slots:
    void startNewControlConnection();

private:
    QString userName;
    QString password;
    QString rootPath;
    QTcpServer *server;
};

#endif // FTPSERVER_H
