#ifndef MONITOR_H
#define MONITOR_H

#include "statefile.h"
#include <QObject>
#include <QList>
#include <QTimer>

class Monitor : public QObject
{
private:
    Q_OBJECT
    QTimer *timer;
    QList<StateFile> objects;
    Monitor();
    ~Monitor(){}
    Monitor(Monitor const &);
    Monitor& operator=(Monitor const&);
public:
    static Monitor& Instance()
    {
        static Monitor s;
        return s;
    }
    bool AddFile(QString path);
    bool DelFile(QString path);
signals:
    void Resized(QString path, qint64 size);
    void Exist(QString path,qint64 size);
    void NotExist(QString path);
    void FirstOut(QString path,qint64 size,bool isExist);

public slots:
    void update();
};

#endif // MONITOR_H
