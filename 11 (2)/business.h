#pragma once
#ifndef BUSINESS_H
#define BUSINESS_H
//定义记录的一笔交易（已经成交的那种）,后期可以考虑由两个commissionBusiness组成,用来显示在核心界面的“分时成交”上
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
    business(stock*_tradingstock,stockholder*_soldholder,stockholder*_buyholder,int _tradingnumber,double _tradingprice);//一笔单子交易成功后，以这些参数初始化信息

protected:
    QTime tradingTime;//这笔单子的成交时间
    QDate tradingDate;//这笔单子的成交日
    stock* tradingStock;//成交的股票
    stockholder* soldHolder;//卖方账户
    stockholder* buyHolder;//买方账户
	int tradingNumber;//交易股数
	double tradingPrice;//成交价格

};
#endif // !BUSINESS_H
