#ifndef STATEFILE_H
#define STATEFILE_H

#include <QString>


class StateFile
{
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

};




#endif // STATEFILE_H
