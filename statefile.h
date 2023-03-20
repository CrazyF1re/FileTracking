#ifndef STATEFILE_H
#define STATEFILE_H

#include <QObject>
#include <QString>
#include <QFileInfo>
#include "output.h"

class StateFile : public QObject
{
    Q_OBJECT
    QString FileName;
    qint64 size;
    bool isExist;
    output out;
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
    void first_out(QString path,qint64 size,bool isExist);
    void out_signal();
public slots:
    void out_slot(){
     emit first_out(this->FileName,this->size,this->isExist);
    }
public:
    StateFile(const StateFile& temp);
    StateFile& operator =(const StateFile& temp);


};
#endif // STATEFILE_H
