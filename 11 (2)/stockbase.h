#pragma once
#ifndef STOCKBASE_H
#define STOCKBASE_H
#include"QString"


//股票基类，包含最基本信息
#include<string>
using namespace std;
class stockbase {//股票基类，包含股票基本不变信息
    friend class MainWindow;
    friend class Finance;
    friend class transactionInformation;
public:
    stockbase(QString,QString,double);

    QString stockName;//股票名
    QString stockCode;//股票代码
	double currentPrice;//股票当前价格

};
#endif
