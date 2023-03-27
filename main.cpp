#include <QCoreApplication>
#include "monitor.h"
#include "output.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Monitor& eye = Monitor::Instance();
    output out;
    QObject::connect(&eye,&Monitor::Resized,&out,&output::outResizedFile);
    QObject::connect(&eye,&Monitor::Exist,&out,&output::outExistFile);
    QObject::connect(&eye,&Monitor::NotExist,&out,&output::outNonExistFile);
    QObject::connect(&eye,&Monitor::FirstOut,&out,&output::FirstOut);
    eye.AddFile("C:\\Users\\Vova\\Downloads\\qt.txt");
    eye.AddFile("C:\\Users\\Vova\\Downloads\\123.txt");
    eye.AddFile("C:\\Users\\Vova\\Downloads\\file3.txt");
    eye.AddFile("C:\\Users\\Vova\\Downloads\\file.txt");
    return a.exec();
}
