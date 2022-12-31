#pragma once
//某只股票每天的信息，用来画k线,成交量线等等
#ifndef STOCKPERDAY_H
#define STOCKPERDAY_H
#include<string>
#include<QDate>
#include"stock.h"
#include"totalclass.h"

using namespace std;

class stockPerDay {//一天的股票信息，收盘时更新，用于画K线
    friend class afterLoginin;
public:
    stockPerDay(QDate ,stock*_fatherstock,double priceEnd,double priceBegin,double highest,double lowest,int tradingNumber);

private:
    QDate day;
    stock* fatherStock;//这个每日信息所属的股票
	double priceEnd;//收盘价
	double priceBegin;//开盘价
	double highest;//今日最高
	double lowest;//今日最低
	int tradingNumber;//日成交量，这个通过交易信息的vector计算


};
#endif // !STOCKPERDAY_H
