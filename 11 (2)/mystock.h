#pragma once
//定义账户持有的某个股票，
#ifndef MYSTOCK_H
#define MYSTOCK_H
#include"stockbase.h"
#include"stockholder.h"
#include"business.h"
#include"totalclass.h"
#include"holdshares.h"

class mystock :public stockbase{//代表被某个股东拥有的某一只股票

    friend class stock;
    friend class stockholder;
    friend class transaction;
    friend class holdShares;
    friend class afterLoginin;

public:
    mystock(QString _name,QString _code,stock*_originstock,int _positionNumber,double _buyprice,
            stockholder*_owningholder);

    ~mystock();


    void modifyMystock(stock*originstock,business*newbisuness=nullptr);//每次市场股票价格变动后，个人股票的一些信息也会随着影响


private:
    //这些应该和word上”账户“里的持仓情况的数据是一一对应的
	int positionNumber;//持股数
	double buyPrice;//买入价
	double totalBuyValue;//买入总额（买入价*持股数）
	double totalCurrentValue;//当前总额（股票当前价格*持股数
	double earning;//盈亏=当前总额-买入总额
    double todaybegin;//用来算下一个数据
	double earningToday;//当日盈亏
	double positionRate;//持股比例 = 当前总额/该账户的当前资金
    stockholder* owningHolder;//该股票拥有者
    stock* originStock;//对应的市场上的股票
	
};
#endif // !MYSTOCK_H
