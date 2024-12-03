#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>

class MyUDP : public QObject
{
    Q_OBJECT

public:
    explicit MyUDP(QObject *parent = nullptr);
    ~MyUDP();

public slots:
    void handleMessage();

private:
    QUdpSocket *socket;
};

#endif // MYUDP_H
