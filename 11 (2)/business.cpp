#include"business.h"

business::business(stock*_tradingstock,stockholder*_soldholder,stockholder*_buyholder,int _tradingnumber,double _tradingprice)
{
    tradingTime=QTime::currentTime(),tradingDate=QDate::currentDate(),tradingStock=_tradingstock,soldHolder=_soldholder;
    buyHolder=_buyholder,tradingNumber=_tradingnumber,tradingPrice=_tradingprice;
}
/*protected:
   QDateTime tradingTime;//这笔单子的成交时间
    stock* tradingStock;//成交的股票
    stockholder* soldHolder;//卖方账户
    stockholder* buyHolder;//买方账户
    int tradingNumber;//交易股数
    double tradingPrice;//成交价格*/
