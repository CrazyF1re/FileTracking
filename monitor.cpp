#include "monitor.h"

Monitor::Monitor()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(1000);

}
bool Monitor::AddFile(QString path)
{
    StateFile temp(path);
    if(objects.contains(temp))
    {
        return false;
    }
    objects.push_back(temp);
    return true;

}
bool Monitor::DelFile(QString path)
{
    StateFile temp(path);
    if(objects.contains(temp))
    {
        objects.removeOne(temp);
//        QObject::disconnect(&temp,&StateFile::ChangedToExist,&out,&output::outExistFile);
//        QObject::disconnect(&temp,&StateFile::ChangedToNonExist,&out,&output::outNonExistFile);
//        QObject::disconnect(&temp,&StateFile::ChangedSize,&out,&output::outResizedFile);
        return true;
    }
    return false;
}

void Monitor::update()
{
    printf_s("Monitor::update()\n");
    for(int i=0;i<objects.size();i++)
    {
        objects[i].update();
    }

}
