#pragma once
//�����˻����е�ĳ����Ʊ��
#ifndef MYSTOCK_H
#define MYSTOCK_H
#include"stockbase.h"
#include"stockholder.h"
#include"business.h"
#include"totalclass.h"
#include"holdshares.h"

class mystock :public stockbase{//����ĳ���ɶ�ӵ�е�ĳһֻ��Ʊ

    friend class stock;
    friend class stockholder;
    friend class transaction;
    friend class holdShares;
    friend class afterLoginin;

public:
    mystock(QString _name,QString _code,stock*_originstock,int _positionNumber,double _buyprice,
            stockholder*_owningholder);

    ~mystock();


    void modifyMystock(stock*originstock,business*newbisuness=nullptr);//ÿ���г���Ʊ�۸�䶯�󣬸��˹�Ʊ��һЩ��ϢҲ������Ӱ��


private:
    //��ЩӦ�ú�word�ϡ��˻�����ĳֲ������������һһ��Ӧ��
	int positionNumber;//�ֹ���
	double buyPrice;//�����
	double totalBuyValue;//�����ܶ�����*�ֹ�����
	double totalCurrentValue;//��ǰ�ܶ��Ʊ��ǰ�۸�*�ֹ���
	double earning;//ӯ��=��ǰ�ܶ�-�����ܶ�
    double todaybegin;//��������һ������
	double earningToday;//����ӯ��
	double positionRate;//�ֹɱ��� = ��ǰ�ܶ�/���˻��ĵ�ǰ�ʽ�
    stockholder* owningHolder;//�ù�Ʊӵ����
    stock* originStock;//��Ӧ���г��ϵĹ�Ʊ
	
};
#endif // !MYSTOCK_H
