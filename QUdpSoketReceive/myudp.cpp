#include "myudp.h"
#include <QDebug>
#include <QHostInfo>

MyUDP::MyUDP(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);

    if (socket->bind(QHostAddress("192.168.0.95"), 2222))  // 수신자 IP
    {
        qDebug() << "Receiver is ready on port 2222";
        connect(socket, SIGNAL(readyRead()), this, SLOT(handleMessage()));
    }
    else
    {
        qDebug() << "Failed to bind to port 2222";
    }
}

void MyUDP::handleMessage()
{
    while (socket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

        if (sender.toString() == "192.168.0.108")  // 송신자의 IP
        {
            qDebug() << "Message from:" << sender.toString();
            qDebug() << "Message port:" << senderPort;
            qDebug() << "Message:" << buffer;
        }
    }
}

MyUDP::~MyUDP()
{
    delete socket;
}
