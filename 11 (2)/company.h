#pragma once
#ifndef COMPANY_H
#define COMPANY_H


//公司
#include"totalclass.h"
#include<QVector>
#include<QDateTime>//注：所有这里先用这个头文件和ctime类代替时间，到了qt上转化成QDateTime类
#include"finance.h"
#include<string>
#include"account.h"
#include"stock.h"
using namespace std;
class company :public account{//以公司身份登录的类的信息，并可以作为一个股票的成员，储存财务信息
    friend class stock;
    friend class Finance;
    friend class ListedCompany;
public:
    company(QString name,QString word, QString,finance *firstfinance);
    void registerInf(int year,int month,double _profit);//公司更改财务信息，参数见界面

protected:
    QDateTime listTime;//上市时间，就记录公司账户成功注册的系统时间（意味着股票通过要求，可以上市）
    QString stockname;
	//公司名和密码继承username
    stock* thisStock;//公司所注册的股票
    finance*myFinance;//公司每个月财务信息


	
};
#endif // !COMPANY_H
