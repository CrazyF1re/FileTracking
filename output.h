#ifndef OUTPUT_H
#define OUTPUT_H
#include <QObject>
class output : public QObject
{
    Q_OBJECT
public:
    output();
public slots:
    void outExistFile(QString temp);
    void outNonExistFile(QString temp);
    void outResizedFile(QString temp, qint64 size);

};

#endif // OUTPUT_H
