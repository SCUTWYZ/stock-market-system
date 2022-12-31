/*#pragma once
#ifndef INNOVATIONPLATESTOCK_H
#define INNOVATIONPLATESTOCK_H


//创业板股
#include"stock.h"
class innovationPlateStock :public stock {
  public:

    innovationPlateStock(company*);
    void beginTrade() override;
//涨跌幅20%（设定这两个成员的时候不同，其它都一样）然后在公司注册界面的上市条件不一样，股票代码主板以1开头，创业板0开头，仅此而已）仅此而已
};
#endif // !INNOVATIONPLATESTOCK_H*///这个头文件写到stock.h里了
