#include <QCoreApplication>
#include "monitor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    printf_s("F");
    printf_s("asd");
    Monitor eye;
    eye.AddFile("C:\\Users\\Vova\\Downloads\\qt.txt");
    eye.AddFile("C:\\Users\\Vova\\Downloads\\123.txt");
    eye.AddFile("C:\\Users\\Vova\\Downloads\\file3.txt");
    eye.AddFile("C:\\Users\\Vova\\Downloads\\file.txt");


    return a.exec();
}
