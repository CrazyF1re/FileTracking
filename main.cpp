#include <QCoreApplication>
#include "monitor.h"
#include "statefile.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Monitor eye;
    eye.AddFile("C:\\Users\\Vova\\Downloads\\qt.txt");
    eye.AddFile("C:\\Users\\Vova\\Downloads\\123.txt");
    eye.AddFile("C:\\Users\\Vova\\Downloads\\file3.txt");
    eye.AddFile("C:\\Users\\Vova\\Downloads\\file.txt");

    return a.exec();
}
