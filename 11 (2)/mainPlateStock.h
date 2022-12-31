/*#pragma once
#ifndef MAINPLATESTOCK_H
#define MAINPLATESTOCK_H

//主板股票
#include"stock.h"
class mainPlateStock :public stock{
public:

    mainPlateStock(company*);

    void beginTrade() override;
	//三种stock的子类之一，准入条件不同，涨跌幅不同，主板为10%
};
#endif // !MAINPLATESTOCK_H*///这个头文件写到stock.h里了
