#include"mystock.h"
mystock::mystock(QString _name,QString _code,stock*_originstock,int _positionNumber,double _buyprice,
                  stockholder*_owningholder)
    :stockbase(_name,_code,_buyprice)
{
    originStock=_originstock;
    owningHolder=_owningholder;
    positionNumber=_positionNumber;
    buyPrice=_buyprice;
    totalBuyValue=buyPrice*positionNumber;
    totalCurrentValue=totalBuyValue;
    earning=0;
    earningToday=0;
    positionRate=totalCurrentValue/(owningHolder->currentMoney);
    todaybegin=totalBuyValue;
}


mystock::~mystock(){}


void mystock::modifyMystock(stock*originstock,business*newbusiness)
{

    currentPrice=originstock->currentPrice;//当前价

    //买入单价

    if(newbusiness->buyHolder==this->owningHolder)
   { totalBuyValue+=newbusiness->tradingPrice*newbusiness->tradingNumber;
         positionNumber+=newbusiness->tradingNumber;//加仓
        buyPrice=totalBuyValue/positionNumber;
   }


   if(newbusiness->soldHolder==this->owningHolder)
    {totalBuyValue-=newbusiness->tradingPrice*newbusiness->tradingNumber;

       positionNumber-=newbusiness->tradingNumber;
        buyPrice=totalBuyValue/positionNumber;
    }



    if (positionNumber<=0)
    {     for(int i=0;i<this->owningHolder->holderStock.size();i++)
        {
            if (this->owningHolder->holderStock[i]==this)
                 this->owningHolder->holderStock.remove(i);
                  break;
        }//如果卖掉后没有持仓的数量了，就删了

     }




    totalCurrentValue=currentPrice*positionNumber;
    \
    earning=totalCurrentValue-totalBuyValue;

    bool todaybuy=false;
    for(int i=0;i<owningHolder->holderbusiness.size();i++)
    {if (owningHolder->holderbusiness[i]->tradingDate==QDate::currentDate()&&
                owningHolder->holderbusiness[i]->tradingStock->stockName==stockName)
            earningToday=totalCurrentValue-positionNumber*buyPrice,todaybuy=true;}

    if(todaybuy==false)
    earningToday=totalCurrentValue-positionNumber*originstock->priceBegin;


    owningHolder->modifyHolderMessage();
    positionRate=totalCurrentValue/(owningHolder->currentMoney);

}


/*class mystock :public stockbase{
public:
    mystock();
    ~mystock();
private://这些应该和word上”账户“里的持仓情况的数据是一一对应的
    int positionNumber;//持股数
    double buyPrice;//买入价
    double totalBuyValue;//买入总额（买入价*持股数）
    double totalCurrentValue;//当前总额（股票当前价格*持股数
    double earning;//盈亏=当前总额-买入总额
    double earningToday;//当日盈亏
    double positionRate;//持股比例 = 当前总额/该账户的当前资金
    stockholder* owningHolder;//该股票拥有者

};*/
