//#pragma once
#ifndef STOCKHOLDER_H
#define STOCKHOLDER_H
#include<string>
#include<QVector>
#include"mystock.h"
#include"business.h"
#include"account.h"
#include"totalclass.h"
#include"afterloginin.h"
 //#include <QMetaType>

#include"commissionBusiness.h"
using namespace std;

//Q_DECLARE_METATYPE(stockholder);
class stockholder:public account{//�ɶ��˻���Ϣ��
    friend class sign1;
    friend class mystock;
    friend class commissionBusiness;
    friend class stock;
    friend class Account;
    friend class holdShares;
    friend class transactionInformation;
    friend class transaction;
    friend class SubscriptionOfNewShares;
    friend class Widget;
    friend class afterLoginin;
public:

    stockholder(QString,double,QString,QString);

    void modifyHolderMessage();//ʵʱ���ݹɼۺͳֲָ����˻�����Ϣ

    ~stockholder();


  //����������������Ϊĳ������Ľ��׺�����������ɶ����������ֻ��Ʊ�����������ֱ�����Ʊ���룬ί�н��׼۸񣨾�����Ը������������ļ۸񣩣����׹�����

    void buyStock(stock *thisstock, double price, int num);
    void sellStock(stock *thisstock, double price, int num);


private:
	double initialMoney;//��ʼ�ɼ�
    QString holderType;//ɢ����������
	double availableMoney;//��ǰ���ã������㶵�ﻹ�е�Ǯ�������еĵ�ǰ���ã�
	double currentMoney;//(��ǰ����+��ǰ�ֲ֣��������еĵ�ǰ�ʽ�
	double currentPositionPrice;//��ǰ�ֲ֣�����(�����й�Ʊ��ǰ�۸�*�����еĹ����������
	double totalEarning;//��ӯ��=��ǰ�ʽ�-��ʼ�ʽ�
	double todayEarning;//����ӯ�����ܺ����
	double earningRate;//�����ʣ���ӯ��/��ʼ�ʽ�
    QVector<mystock*>holderStock;//�ֲ����
    QVector<commissionBusiness*>holdercommission;//ί�н��׵ĵ��ӣ�Ҳ���ǽ�����Ϣ����δ�ɽ���
    QVector<business*>holderbusiness;//�ѳɽ��ĵ���


	

};
#endif
