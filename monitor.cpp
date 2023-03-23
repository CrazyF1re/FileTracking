#include "monitor.h"

Monitor::Monitor()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
}
bool Monitor::AddFile(QString path)
{
    StateFile temp(path);
    if(objects.contains(temp))
    {
        return false;
    }
    objects.push_back(temp);
    emit FirstOut(temp.GetFileName(),temp.GetSize(),temp.GetExist());
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
        StateFile temp = objects[i];
        if (objects[i].update())
        {
            if (temp.GetExist() && !objects[i].GetExist())// существует => не существует
            {
                emit NotExist(objects[i].GetFileName());
            }
            else if (!temp.GetExist() && objects[i].GetExist())//не существует => существует
            {
                emit Exist(objects[i].GetFileName(),objects[i].GetSize());
            }
            else//изменен раземер
            {
                emit Resized(objects[i].GetFileName(),objects[i].GetSize());
            }
        }
    }

}
