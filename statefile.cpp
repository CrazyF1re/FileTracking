#include "statefile.h"


StateFile::StateFile()
{
    FileName = "";
    size = 0;
    isExist = 0;
    QObject::connect(this, &StateFile::ChangedSize, test);
}
StateFile::StateFile(QString path)
{
    QFileInfo file(path);
    FileName = file.path()+"\\"+file.fileName();
    size = file.size();
    isExist = file.exists();
    QObject::connect(this, &StateFile::ChangedSize, test);
}
void StateFile::update()
{
    QFileInfo temp = QFileInfo(FileName);

    if(temp.exists() && !isExist)//если файл существует, хотя до этого его не было
    {
        printf_s("Existing\n");
        isExist = true;
        emit ChangedToExist(FileName);
    }
    else if(!temp.exists() && isExist)//если файл не существует, хотя до этого существовал
    {
        printf_s("NotExisting\n");
        isExist = false;
        size = 0;
        emit ChangedToNonExist(FileName);
    }
    else if(temp.size()!= size)//если файл изменил свой размер
    {
        printf_s("Resized\n");
        size = temp.size();
        emit ChangedSize(FileName,size);
    }
}

QString StateFile::getFileName(){ return FileName;}
bool StateFile::getIsExist(){return isExist;}
qint64 StateFile::getSize(){return size;}



StateFile::StateFile(const StateFile& temp)
{
    FileName = temp.FileName;
    isExist = temp.isExist;
    size = temp.size;

}
StateFile& StateFile::operator =(const StateFile& temp)
{
    FileName = temp.FileName;
    isExist = temp.isExist;
    size = temp.size;
    return *this;

}
