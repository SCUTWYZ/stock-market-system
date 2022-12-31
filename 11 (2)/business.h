#pragma once
#ifndef BUSINESS_H
#define BUSINESS_H
//�����¼��һ�ʽ��ף��Ѿ��ɽ������֣�,���ڿ��Կ���������commissionBusiness���,������ʾ�ں��Ľ���ġ���ʱ�ɽ�����
#include<QTime>
#include<QDate>
#include"stockholder.h"
#include"stock.h"
#include"totalclass.h"
using namespace std;

class business{
    friend class mystock;
    friend class stock;
    friend class MainWindow;
    friend class transactionInformation;


public:
    business(stock*_tradingstock,stockholder*_soldholder,stockholder*_buyholder,int _tradingnumber,double _tradingprice);//һ�ʵ��ӽ��׳ɹ�������Щ������ʼ����Ϣ

protected:
    QTime tradingTime;//��ʵ��ӵĳɽ�ʱ��
    QDate tradingDate;//��ʵ��ӵĳɽ���
    stock* tradingStock;//�ɽ��Ĺ�Ʊ
    stockholder* soldHolder;//�����˻�
    stockholder* buyHolder;//���˻�
	int tradingNumber;//���׹���
	double tradingPrice;//�ɽ��۸�

};
#endif // !BUSINESS_H
