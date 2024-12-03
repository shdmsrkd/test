#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QString>

class MyUDP : public QObject
{
    Q_OBJECT

public:
    explicit MyUDP(QObject *parent = nullptr);
    ~MyUDP();

    void sendMessage(const QString &message, const QString &receiverIP, quint16 receiverPort);

private:
    QUdpSocket *socket;
};

#endif // MYUDP_H

