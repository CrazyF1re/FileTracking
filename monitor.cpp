#include "monitor.h"

Monitor::Monitor()
{

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
        return true;
    }
    return false;
}

void Monitor::update()
{
    for(int i=0;i<objects.size();i++)
    {
        objects[i].update();
    }
}
