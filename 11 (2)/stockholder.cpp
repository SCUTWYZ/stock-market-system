#include"stockholder.h"
#include"account.h"
stockholder::stockholder(QString _holderType,double _initialMoney,QString _userName,QString _password)
    :initialMoney(_initialMoney),holderType(_holderType)
{userName=_userName;password=_password;
    availableMoney=initialMoney;
    currentMoney=availableMoney;
    currentPositionPrice=0;
    totalEarning=0;
    todayEarning=0;
    earningRate=0;

}

stockholder::~stockholder() {}

void stockholder::buyStock(stock *thisstock, double price, int num) {
    commissionBusiness* buycommissionBusiness = new commissionBusiness (this, true, thisstock, num, price);
    holdercommission.push_back(buycommissionBusiness);
    thisstock->comofBuy.push_back(buycommissionBusiness);
    thisstock->strike();


}//这两个就是作为某个对象的交易函数，三个参数分别代表股票代码，委托交易价格（就是你愿意买入或卖出的价格），交易股数）

void stockholder::sellStock(stock *thisstock, double price, int num) {
    commissionBusiness* buycommissionBusiness = new commissionBusiness (this,false, thisstock, num, price);
    holdercommission.push_back(buycommissionBusiness);
    thisstock->comofSell.push_back(buycommissionBusiness);
    thisstock->strike();
}



void stockholder::modifyHolderMessage(){

    currentPositionPrice=0;
    for(int i=0;i<holderStock.size();i++)
      currentPositionPrice+=holderStock[i]->totalCurrentValue;

    currentMoney=availableMoney+currentPositionPrice;

    totalEarning=currentMoney-initialMoney;

      todayEarning=0;
     for(int i=0;i<holderStock.size();i++)
   todayEarning+=holderStock[i]->earningToday;

     earningRate=totalEarning/initialMoney;
 }//在stock.cpp里修改当前的可用和两个vector，剩余的信息在这里更新


/*double initialMoney;//初始股价
string holderType;//散户或者主力
double availableMoney;//当前可用，就是你兜里还有的钱（界面中的当前可用）
double currentMoney;//(当前可用+当前持仓）（界面中的当前资金）
double currentPositionPrice;//当前持仓，就是(所持有股票当前价格*所持有的股数）的求和
double totalEarning;//总盈亏=当前资金-初始资金
double todayEarning;//今日盈亏，很好理解
double earningRate;//收益率：总盈亏/初始资金
vector<mystock>holderStock;//持仓情况
vector<commissionBusiness>holdercommission;//委托交易的单子，也就是交易信息7*/
