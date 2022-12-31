#pragma once
#ifndef COMMISSIONBUSINESS_H
#define COMMISSIONBUSINESS_H


//ί�н��׵�����û�гɽ���ֻ����ĳһ���˻�ί�еĵ��ӣ�
#include"stock.h"
#include"stockholder.h"
#include<QDateTime>
#include"business.h"
#include"totalclass.h"
class commissionBusiness {
	friend class stock;
    friend class MainWindow;
    friend class transactionInformation;
public:
    commissionBusiness( stockholder *_thisHolder, bool _isbuy,stock *_thisStock, int _comNumber ,double _comPrice);//��stockholder��������������׺���������������һ������
    void withdraw();//��������ӣ����û�ɽ����Գ���


private:
    stockholder *thisHolder;//������ӵĶ����˻�
	bool isbuy;//���򵥣���or������
	bool isComplete;//�Ƿ�ɽ�������δ�ɽ�
    stock *thisStock;//������ί�н��׵Ĺ�Ʊ
	int comNumber;//ί�еĹ�����������100�ı�����
	double comPrice;//ί�еļ۸�
    QDateTime comTime;//ί�е�ʱ�䣨��Ϊ��ͬ�Ĺ�Ʊ����ͬ�ļ۸�����г��ϣ���������ϳɽ��������ĸ��Ⱦ��ĸ��ȳɽ���


};
#endif
