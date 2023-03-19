#ifndef STATEFILE_H
#define STATEFILE_H

#include <QObject>
#include <QString>
#include <QFileInfo>
#include "output.h"

class StateFile : public QObject
{
    Q_OBJECT
    output out;
    QString FileName;
    qint64 size;
    bool isExist;
public:
    QString getFileName();
    qint64 getSize();
    bool getIsExist();
public:
    StateFile();
    StateFile(QString path);
    bool operator==(const StateFile& e1) const
        {
                return e1.FileName == FileName && e1.size == size && e1.isExist == isExist;
        }
    void update();
signals:
    void ChangedToExist(QString FileName);
    void ChangedSize(QString FileName, qint64 size);
    void ChangedToNonExist(QString FileName);

public:
    StateFile(const StateFile& temp);
    StateFile& operator =(const StateFile& temp);
public slots:
    void test(QString FileName,qint64 size)
    {
        qDebug()<<FileName;
        printf_s("%s , %d",FileName.toStdString().c_str(),size);
    }

};
#endif // STATEFILE_H
