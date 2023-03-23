#ifndef STATEFILE_H
#define STATEFILE_H

#include <QObject>
#include <QString>
#include <QFileInfo>

class StateFile : public QObject
{
    Q_OBJECT
    QString FileName;
    qint64 size;
    bool isExist;
public:
    StateFile();
    StateFile(QString path);
    bool operator==(const StateFile& e1) const;
    bool update();
    //Getters
    QString GetFileName();
    qint64 GetSize();
    bool GetExist();
signals:
    void ChangedToExist(QString FileName);
    void ChangedSize(QString FileName, qint64 size);
    void ChangedToNonExist(QString FileName);
public:
    StateFile(const StateFile& temp);
    StateFile& operator =(const StateFile& temp);


};
#endif // STATEFILE_H
