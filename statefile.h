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
protected:
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
    ChangedToExist(QString path);
    ChangedSize(qint64 size);
    ChangedToNonExist(QString path);





public:
    StateFile(const StateFile& temp);
    StateFile& operator =(const StateFile& temp);


};
#endif // STATEFILE_H
