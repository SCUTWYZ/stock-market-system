#pragma once
#ifndef FINANCE_H
#define FINANCE_H
#include"QDateTime"
#include"listedcompany.h"
//公司某个月的财务信息，有些为什么要乘12呢，因为这里我们按月算，但是实际这些名词都是按照年来算）

class finance {   //储存一个公司的财务信息
   friend class company;
   friend class stock;
   friend class Finance;
   friend class ListedCompany;
public:
    finance(int year,int month,double _profit,double _stockNumber,double _stockinitialPrice);//注册公司的时候初始化财务信息
    void modify(int year,int month,double _profit);//更新财务信息


protected:
	int registerYear;//公司这次财务信息的填写年
	int registerMonth;//公司这次财务信息的填写月 （注：如果下个月没有填写，则顺延上个月）
	double profit;//利润,后来每次只要填这一个
	double totalValue;// 公司当前总市值  上期总市值+利润
	double stockNumber;//股数
	double stockinitialPrice;//发行股价（也就是界面里填的每股金额）
	double realValue;// 每股净资产（ 上期的每股净资产+利润/总股数，最初的每股净资产为发行股价）
	double ROE;//净资产收益率（公司利润*12/（上期每股净资产*股数））
	double EPS;//每股收益   （每股净资产-上期每股净资产）*12
	

};
#endif // !FINANCE_H
