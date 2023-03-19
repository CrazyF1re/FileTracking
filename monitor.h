#ifndef MONITOR_H
#define MONITOR_H
#include "statefile.h"
#include <QList>
class Monitor
{
    QList<StateFile> objects;
public:
    Monitor();
    bool AddFile(QString path);
    bool DelFile(QString path);

};

#endif // MONITOR_H
