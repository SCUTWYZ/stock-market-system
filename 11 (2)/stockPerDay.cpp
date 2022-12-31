#include"stockPerDay.h"
#include"stock.h"
stockPerDay:: stockPerDay(QDate day,stock*_fatherstock,double _priceEnd,double _priceBegin,double _highest,double _lowest,int _tradingNumber){
    this->day=day, fatherStock=_fatherstock,priceEnd=_priceEnd,priceBegin=_priceBegin,highest=_highest,lowest=_lowest,tradingNumber=_tradingNumber;
}

/*QDate day;
stock* fatherStock;//这个每日信息所属的股票
double priceEnd;//收盘价
double priceBegin;//开盘价
double highest;//今日最高
double lowest;//今日最低
int tradingNumber;//日成交量，这个通过交易信息的vector计算*/
