#include "statefile.h"


StateFile::StateFile()
{
    FileName = "";
    size = 0;
    isExist = 0;
}

StateFile::StateFile(QString path)
{
    QFileInfo file(path);
    FileName = file.path()+"\\"+file.fileName();
    size = file.size();
    isExist = file.exists();
    QObject::connect(this, &StateFile::first_out,&out ,&output::FirstOut);
    QObject::connect(this, &StateFile::out_signal,this ,out_slot);
}
void StateFile::update()
{
    QFileInfo temp = QFileInfo(FileName);
    QObject::connect(this, &StateFile::ChangedSize,&out ,&output::outResizedFile);
    QObject::connect(this, &StateFile::ChangedToExist,&out ,&output::outExistFile);
    QObject::connect(this, &StateFile::ChangedToNonExist,&out ,&output::outNonExistFile);
    if(temp.exists() && !isExist)//если файл существует, хотя до этого его не было
    {
        isExist = true;
        emit ChangedToExist(FileName);
    }
    else if(!temp.exists() && isExist)//если файл не существует, хотя до этого существовал
    {
        isExist = false;
        size = 0;
        emit ChangedToNonExist(FileName);
    }
    else if(temp.size()!= size)//если файл изменил свой размер
    {
        size = temp.size();
        emit ChangedSize(FileName,size);
    }
    QObject::disconnect(this, &StateFile::ChangedSize,&out ,&output::outResizedFile);
    QObject::disconnect(this, &StateFile::ChangedToExist,&out ,&output::outExistFile);
    QObject::disconnect(this, &StateFile::ChangedToNonExist,&out ,&output::outNonExistFile);
}





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
