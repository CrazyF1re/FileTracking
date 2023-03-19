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
