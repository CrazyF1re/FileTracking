#ifndef MONITOR_H
#define MONITOR_H

#include "statefile.h"
#include <QObject>
#include <QList>

class Monitor : public QObject
{
    Q_OBJECT
    QList<StateFile> objects;
public:
    Monitor();
    bool AddFile(QString path);
    bool DelFile(QString path);
    void update();
};

#endif // MONITOR_H
