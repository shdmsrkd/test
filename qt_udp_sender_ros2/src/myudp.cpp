#include "myudp.hpp"
#include <QDebug>

MyUDP::MyUDP(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
}

MyUDP::~MyUDP()
{
    delete socket;
}

void MyUDP::sendMessage(const QString &message, const QString &receiverIP, quint16 receiverPort)
{
    QByteArray data;
    data.append(message);

    QHostAddress address(receiverIP);
    socket->writeDatagram(data, address, receiverPort);
    qDebug() << "Message sent to" << receiverIP << ":" << receiverPort;
}

