#include"stock.h"

mainPlateStock::mainPlateStock(company*thiscompany)
      :stock(thiscompany)
{

}
void mainPlateStock::beginTrade(){
    canTrade=true;
    priceBegin=currentPrice;
    limitUp=priceBegin*1.1;
    limitDown=priceBegin*0.9;
    highest=priceBegin;
    lowest=priceBegin;
    totalHandToday=0;

}
