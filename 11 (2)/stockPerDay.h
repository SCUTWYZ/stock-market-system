#pragma once
//ĳֻ��Ʊÿ�����Ϣ��������k��,�ɽ����ߵȵ�
#ifndef STOCKPERDAY_H
#define STOCKPERDAY_H
#include<string>
#include<QDate>
#include"stock.h"
#include"totalclass.h"

using namespace std;

class stockPerDay {//һ��Ĺ�Ʊ��Ϣ������ʱ���£����ڻ�K��
    friend class afterLoginin;
public:
    stockPerDay(QDate ,stock*_fatherstock,double priceEnd,double priceBegin,double highest,double lowest,int tradingNumber);

private:
    QDate day;
    stock* fatherStock;//���ÿ����Ϣ�����Ĺ�Ʊ
	double priceEnd;//���̼�
	double priceBegin;//���̼�
	double highest;//�������
	double lowest;//�������
	int tradingNumber;//�ճɽ��������ͨ��������Ϣ��vector����


};
#endif // !STOCKPERDAY_H
