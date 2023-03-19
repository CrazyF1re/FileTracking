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
QString StateFile::getFileName(){ return FileName;}
bool StateFile::getIsExist(){return isExist;}
qint64 StateFile::getSize(){return size;}
