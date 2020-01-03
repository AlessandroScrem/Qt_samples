#include "myrunnable.h"

MyRunnable::MyRunnable() : QRunnable()
{

}

void MyRunnable::run()
{
    if (!SocketDesctriptor)return;

    QTcpSocket socket;
    socket.setSocketDescriptor(SocketDesctriptor);

    socket.write("hello world:");
    socket.flush();
    socket.waitForBytesWritten();
    socket.close();


}
