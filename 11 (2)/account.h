#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
//�˻����࣬���ɶ��ࣨstockholder)�͹�˾�ࣨcompany���̳�
#include<QString>
using namespace std;
class account{
    friend class sign1;
    friend class Widget;
public:
    account();
    ~account();


    QString userName;//�û�������˾����
    QString password;//���루�Լ����ã����ǹɶ��͹�˾�Ĺ�ͬ���ԣ��ϵ۲��������
protected:
};
#endif
