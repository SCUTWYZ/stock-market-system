#include"stock.h"
innovationPlateStock::innovationPlateStock(company*com)
    :stock(com)
{

}

void innovationPlateStock::beginTrade(){
    canTrade=true;
    priceBegin=currentPrice;
    limitUp=priceBegin*1.2;
    limitDown=priceBegin*0.8;
    highest=priceBegin;
    lowest=priceBegin;
    totalHandToday=0;
}
