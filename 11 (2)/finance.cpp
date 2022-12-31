#include"finance.h"
finance::finance(int year,int month,double _profit,double _stockNumber,double _stockinitialPrice){
    registerYear=year,registerMonth=month, profit=_profit,totalValue=_stockNumber*_stockinitialPrice,stockNumber=_stockNumber,stockinitialPrice=_stockinitialPrice;
    realValue=_stockinitialPrice,ROE=0,EPS=0;
}

void finance::modify(int year,int month,double _profit){
     registerYear=year,registerMonth=month,profit=_profit,totalValue+=profit,ROE=12*profit/(stockNumber*realValue),realValue+=profit/stockNumber,EPS=12*profit/stockNumber;
}
/*protected:
    int registerYear;//公司这次财务信息的填写年
    int registerMonth;//公司这次财务信息的填写月 （注：如果下个月没有填写，则顺延上个月）
    double profit;//利润,后来每次只要填这一个
    double totalValue;// 公司当前总市值  上期总市值+利润
    double stockNumber;//股数
    double stockinitialPrice;//发行股价（也就是界面里填的每股金额）
    double realValue;// 每股净资产（ 上期的每股净资产+利润/总股数，最初的每股净资产为发行股价）
    double ROE;//净资产收益率（公司利润*12/（上期每股净资产*股数））
    double EPS;//每股收益   （每股净资产-上期每股净资产）*12
    */
