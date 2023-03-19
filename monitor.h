#ifndef MONITOR_H
#define MONITOR_H

//#include "output.h"
#include "statefile.h"
#include <QObject>
#include <QList>
#include <QTimer>

class Monitor : public QObject
{
    Q_OBJECT
    QTimer *timer;
    QList<StateFile> objects;
public:
    Monitor();
    bool AddFile(QString path);
    bool DelFile(QString path);
public slots:
    void update();
};

#endif // MONITOR_H
