#include "statefile.h"
#include <QFileInfo>

StateFile::StateFile()
{
    FileName = "";
    size = 0;
    isExist = 0;
}
StateFile::StateFile(QString path)
{
    QFileInfo file(path);
    FileName = file.fileName();
    size = file.size();
    isExist = file.exists();
}

void StateFile::update()
{
    QFileInfo temp = QFileInfo(FileName);
    if(temp.exists() && !isExist)//если файл существует, хотя до этого его не было
    {
        isExist = true;
        emit ChangedToExist(FileName);
    }
    else if(!temp.exists() && isExist)//если файл не существует, хотя до этого существовал
    {
        isExist = false;
        emit ChangedToNonExist(FileName);
    }
    else if(temp.size()!= size)//если файл изменил свой размер
    {
        size = temp.size();
        emit ChangedSize(size);
    }
}

QString StateFile::getFileName(){ return FileName;}
bool StateFile::getIsExist(){return isExist;}
qint64 StateFile::getSize(){return size;}
