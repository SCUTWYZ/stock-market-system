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
class stockholder:public account{//股东账户信息类
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

    void modifyHolderMessage();//实时根据股价和持仓更改账户的信息

    ~stockholder();


  //以下这两个就是作为某个对象的交易函数，以这个股东的身份买这只股票，三个参数分别代表股票代码，委托交易价格（就是你愿意买入或卖出的价格），交易股数）

    void buyStock(stock *thisstock, double price, int num);
    void sellStock(stock *thisstock, double price, int num);


private:
	double initialMoney;//初始股价
    QString holderType;//散户或者主力
	double availableMoney;//当前可用，就是你兜里还有的钱（界面中的当前可用）
	double currentMoney;//(当前可用+当前持仓）（界面中的当前资金）
	double currentPositionPrice;//当前持仓，就是(所持有股票当前价格*所持有的股数）的求和
	double totalEarning;//总盈亏=当前资金-初始资金
	double todayEarning;//今日盈亏，很好理解
	double earningRate;//收益率：总盈亏/初始资金
    QVector<mystock*>holderStock;//持仓情况
    QVector<commissionBusiness*>holdercommission;//委托交易的单子，也就是交易信息（还未成交）
    QVector<business*>holderbusiness;//已成交的单子


	

};
#endif
