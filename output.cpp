#include "output.h"

void output::outExistFile(QString temp, qint64 size)
{
    std::cout<< "File "<<temp.toStdString().c_str()<< " exists, size: "<< size<<std::endl;
}
void output::outNonExistFile(QString temp)
{
    std::cout<<"File "<< temp.toStdString().c_str()<< " does not exist"<<std::endl;
}
void output::outResizedFile(QString temp, qint64 size)
{
    std::cout<<"File "<< temp.toStdString().c_str()<<" changed size, new_size: "<<size<<std::endl;
}
void output::FirstOut(QString path, qint64 size, bool isExist)
{
    if (isExist)
    {
        std::cout<<"File "<< path.toStdString().c_str()<<" exist, size: " <<size<<std::endl;

    }
    else
    {
        std::cout<<"File "<<path.toStdString().c_str()<<" does not exist"<<std::endl;

    }
}
