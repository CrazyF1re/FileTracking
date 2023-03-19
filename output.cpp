#include "output.h"


output::output()
{

}


void output::outExistFile(QString temp)
{

    printf_s("File %s exists, size: (((", temp.toStdString().c_str());
}
void output::outNonExistFile(QString temp)
{
    printf_s("File %s does not exist", temp.toStdString().c_str());
}
void output::outResizedFile(QString temp, qint64 size)
{
    printf_s("123");
    printf_s("File %s changed size, new_size: %d",temp.toStdString().c_str(),size);
}
