#include "output.h"


output::output()
{

}
void  output::FirstOut(QString path, qint64 size, bool isExist)
{
    if (!isExist){
        printf_s("File %s does not exist\n", path.toStdString().c_str());
    }
    else
    {
        printf_s("File %s exist, size: %d\n",path.toStdString().c_str(),size);
    }
}

void output::outExistFile(QString temp)
{

    printf_s("File %s exists, size: (((\n", temp.toStdString().c_str());
}
void output::outNonExistFile(QString temp)
{
    printf_s("File %s does not exist\n", temp.toStdString().c_str());
}
void output::outResizedFile(QString temp, qint64 size)
{
    printf_s("File %s changed size, new_size: %d\n",temp.toStdString().c_str(),size);
}
