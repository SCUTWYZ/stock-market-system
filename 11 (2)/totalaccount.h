#ifndef TOTALACCOUNT_H
#define TOTALACCOUNT_H
#include<QVector>
#include"stockholder.h"
#include"QList"


class totalaccount
{//储存账户
public:totalaccount();
    QVector<stockholder*>vec;
};

#endif // TOTALACCOUNT_H
