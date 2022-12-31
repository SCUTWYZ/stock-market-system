#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
//账户基类，被股东类（stockholder)和公司类（company）继承
#include<QString>
using namespace std;
class account{
    friend class sign1;
    friend class Widget;
public:
    account();
    ~account();


    QString userName;//用户名（公司名）
    QString password;//密码（自己设置），是股东和公司的共同属性；上帝不归这个管
protected:
};
#endif
