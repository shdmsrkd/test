#include <QCoreApplication>
#include "myudp.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    MyUDP sender;
    sender.sendMessage("Hello from UDP Sender", "192.168.0.95", 2222);
    return app.exec();
}

