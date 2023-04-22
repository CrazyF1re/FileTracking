#include "output.h"

void output::outExistFile(QString temp, qint64 size)//File exists, print its size
{
    std::cout<< "File "<<temp.toStdString().c_str()<< " exists, size: "<< size<<std::endl;
}
void output::outNonExistFile(QString temp)//File does not exist, print info
{
    std::cout<<"File "<< temp.toStdString().c_str()<< " does not exist"<<std::endl;
}
void output::outResizedFile(QString temp, qint64 size)//File resized, print new size
{
    std::cout<<"File "<< temp.toStdString().c_str()<<" changed size, new_size: "<<size<<std::endl;
}
void output::FirstOut(QString path, qint64 size, bool isExist)// Here is first print when file just added under surveillance
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
