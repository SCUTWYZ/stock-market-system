#pragma once
#ifndef COMMISSIONBUSINESS_H
#define COMMISSIONBUSINESS_H


//委托交易单（还没有成交，只是由某一个账户委托的单子）
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
    commissionBusiness( stockholder *_thisHolder, bool _isbuy,stock *_thisStock, int _comNumber ,double _comPrice);//在stockholder类里面的两个交易函数可以生成这样一个单子
    void withdraw();//对这个单子，如果没成交可以撤单


private:
    stockholder *thisHolder;//这个单子的对象账户
	bool isbuy;//是买单？（or卖单）
	bool isComplete;//是否成交？还是未成交
    stock *thisStock;//单子所委托交易的股票
	int comNumber;//委托的股数（必须是100的倍数）
	double comPrice;//委托的价格
    QDateTime comTime;//委托的时间（因为相同的股票，相同的价格放在市场上，如果都符合成交条件，哪个先就哪个先成交）


};
#endif
