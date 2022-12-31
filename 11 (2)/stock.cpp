#include"stock.h"
#include<QtAlgorithms>
stock::stock(company*thiscompany)//注册股票初始化信息
    :stockbase(thiscompany->stockname,"",thiscompany->myFinance->stockinitialPrice)
{
    totalHandToday=0;//初始化
    thisCompany=thiscompany;
    priceEnd=0;
    canTrade=false;
    totalStockNumber=thiscompany->myFinance->stockNumber;

    tobeBuy=totalStockNumber;
    initialPrice=thiscompany->myFinance->stockinitialPrice;
    currentPrice=initialPrice;
    historicalLowest=currentPrice;
    historicalHighest=currentPrice;
    priceBegin=currentPrice;
    modifystockmessage(thiscompany->myFinance->stockinitialPrice);
   }




bool stock::cantrade()
{
    return canTrade;
}     //获取值，是否可以买卖




void stock::modifystockmessage(double newPrice)//包括更改价格和更改利润
{
    currentPrice=newPrice;
    currentTotalPrice=currentPrice*totalStockNumber;
    raisingPrice=currentPrice-priceBegin;
    raisingRate=raisingPrice/priceBegin;


    if(newPrice>=highest)
        highest=newPrice;
    if(newPrice<=lowest)
        lowest=newPrice;
    if(newPrice>=historicalHighest)
        historicalHighest=newPrice;
    if(newPrice<=historicalLowest)
        historicalLowest=newPrice;


    totalRaisingRate=(currentPrice-initialPrice)/initialPrice;
    realValue=thisCompany->myFinance->realValue;
    ROE=thisCompany->myFinance->ROE;
    PB=currentPrice/realValue;
    EPS=thisCompany->myFinance->EPS;
    PER=currentPrice/EPS;



}



void stock::switchtoTrade(){
    beginTrade();
    modifystockmessage(this->initialPrice);
    canTrade=true;}

//stock::~stock(){}



//下面是最核心的代码算法 给它让道！！！！！1（成交）
//第一步 按照一定条件先分类遍历排序查找所有的委托单子
//第二步 显示 打印 盘口信息
//第三步  达成交易（比如 只要有新的委托单产生就调用一次这个函数 或者过几秒就调用一次）
//第四步 判断交易成功后 生成新的business对象并添加到vector 更新股价和其它一系列信息 包括stockholder的信息
/*细分步骤：
* 1 某一刻的所有委托信息分成两类，首先对价格排序，同一价格对时间排序（价格分别升序和降序），
  2.选择前五个价格，统计相应的手数，打印到盘口
* 3..对买方的委托对象执行算法：仅仅参考其价格，对第一个卖单和第一个买单，如价格<=买单，则成交这笔交易，交易数量为对应买卖单中最小的，生成的这笔创建一个business对象，显示出来）
* （每生成一个business就相应更改各种股票的基本信息，板块的基本信息等等）
* 4..如果委托数量不相同，则修改成交但没完全成交的买卖单信息的委托股数为一个新的委托单，数量完全成交的从vector里去除，把后面的单往前移，生成新的vector，继续从第二步执行，直到没有交易为止
* 5.如果新产生了一个委托单，就调用一次这个函数
*/




bool stock:: GreaterSort (commissionBusiness*a,commissionBusiness*b) //对买单排序，出价越高越好
{if(a->comPrice!=b->comPrice)
 return (a->comPrice>b->comPrice);
else
 return(a->comTime>b->comTime);
}



bool stock::LessSort (commissionBusiness*a,commissionBusiness*b) //卖单，出价越低越前
{if(a->comPrice!=b->comPrice)
        return (a->comPrice<b->comPrice);
       else
        return(a->comTime>b->comTime); }




void stock::strike(){
   if(cantrade()==true)

   {

    qSort(comofBuy.begin(),comofBuy.end(),GreaterSort);
    qSort(comofSell.begin(),comofSell.end(),LessSort);

    while (comofBuy.size()>0&&comofSell.size()>0&&comofBuy[0]->comPrice>=comofSell[0]->comPrice)
    {
        business* newbusiness=new business(this,comofSell[0]->thisHolder,comofBuy[0]->thisHolder,min(comofBuy[0]->comNumber,comofSell[0]->comNumber),comofSell[0]->comPrice);

        modifystockmessage(comofSell[0]->comPrice);//修改股票基本信息


        //下面是修改相应的账户持仓股票
        bool hasA=false;
        for(int i=0;i<newbusiness->buyHolder->holderStock.size();i++)
        {
            if(newbusiness->buyHolder->holderStock[i]->originStock==newbusiness->tradingStock)
               {
                newbusiness->buyHolder->holderStock[i]->modifyMystock(newbusiness->tradingStock,newbusiness);
                hasA=true;
                break;
               }
         }
            if (!hasA)
         {newbusiness->buyHolder->holderStock.append(new mystock(newbusiness->tradingStock->stockName,
             newbusiness->tradingStock->stockCode,newbusiness->tradingStock,newbusiness->tradingNumber,newbusiness->tradingPrice,
                     newbusiness->buyHolder));
         }


            for(int i=0;i<newbusiness->soldHolder->holderStock.size();i++)
            {
                if(newbusiness->soldHolder->holderStock[i]->originStock==newbusiness->tradingStock)
                   {
                    newbusiness->soldHolder->holderStock[i]->modifyMystock(newbusiness->tradingStock,newbusiness);
                    break;
                   }
             }


//为business增加元素
        businessMessage.push_front(newbusiness);
        newbusiness->buyHolder->holderbusiness.push_front(newbusiness);
        newbusiness->soldHolder->holderbusiness.push_front(newbusiness);
        totalHandToday+=min(comofBuy[0]->comNumber,comofSell[0]->comNumber)/100;

//委托单信息修改
         int a=min(comofBuy[0]->comNumber,comofSell[0]->comNumber);
         comofBuy[0]->comNumber-=a;
         comofSell[0]->comNumber-=a;
         if (comofBuy[0]->comNumber<=0)
         {
             for(int i=0;i<comofBuy[0]->thisHolder->holdercommission.size();i++)
             {
                 if (comofBuy[0]->comTime==comofBuy[0]->thisHolder->holdercommission[i]->comTime)
                 {comofBuy[0]->thisHolder->holdercommission.remove(i);
                     break;
                 }
             }

             comofBuy.removeFirst();
          }


         if (comofSell[0]->comNumber<=0)
         {
             for(int i=0;i<comofSell[0]->thisHolder->holdercommission.size();i++)
             {
                 if (comofSell[0]->comTime==comofSell[0]->thisHolder->holdercommission[i]->comTime)
                 {comofSell[0]->thisHolder->holdercommission.remove(i);
                     break;
                  }
             }
             comofSell.removeFirst();

         }//数量为0，则这个委托单消失


         newbusiness->buyHolder->availableMoney-=newbusiness->tradingPrice*newbusiness->tradingNumber;//更改账户持仓信息
         newbusiness->soldHolder->availableMoney+=newbusiness->tradingPrice*newbusiness->tradingNumber;
       }
 }
}
//最核心的实现交易的函数




void stock::showbuyPriceList()
{
    stockholder *holder1=new stockholder("",99999999999,"","");
    BuyPriceList.clear();
    if(comofBuy.size()!=0)
     {
    BuyPriceList.append(new commissionBusiness(holder1,1,comofBuy[0]->thisStock,comofBuy[0]->comNumber,comofBuy[0]->comPrice));

    int j=1;
    for(int i=0;i<5;i++)
    {

        while(j<comofBuy.size())
        {
            if(comofBuy[j]->comPrice==BuyPriceList[i]->comPrice)
            {
            BuyPriceList[i]->comNumber+=comofBuy[j]->comNumber;
             j++;
            }
        else
             {
                BuyPriceList.append(new commissionBusiness(holder1,1,comofBuy[j]->thisStock,comofBuy[j]->comNumber,comofBuy[j]->comPrice));
              j++;
             break;
             }
        }
    }//end while1

    }
}

void stock::showsellPriceList(){
     stockholder *holder1=new stockholder("",99999999999,"","");
    SellPriceList.clear();
    if(comofSell.size()!=0)
     {
    SellPriceList.append(new commissionBusiness(holder1,1,comofSell[0]->thisStock,comofSell[0]->comNumber,comofSell[0]->comPrice));
    int j=1;
    for(int i=0;i<5;i++)
    {
    while(j<comofSell.size())
    {
        if(comofSell[j]->comPrice==SellPriceList[i]->comPrice)
        {
        SellPriceList[i]->comNumber+=comofSell[j]->comNumber;
         j++;
        }
    else
         {
            SellPriceList.append(new commissionBusiness(holder1,1,comofSell[j]->thisStock,comofSell[j]->comNumber,comofSell[j]->comPrice));
          j++;
         break;
         }
    }//end while2

    }

     }
}

//买卖1-5信息的修改,盘口信息



//核心算法完成





void stock::endTrade()
{
    canTrade=false;
    priceEnd=currentPrice;
    stockPerDay *perday=new stockPerDay(QDate::currentDate(),this,priceEnd,priceBegin,highest,lowest,totalHandToday);
    dayMessage.push_back(perday);

}     //每天停盘



/*QVector<stockPerDay*>dayMessage;//每天的信息
QVector<business*>businessMessage;//画分时成交量图要用到里面的数据，是某个股票已成交的信息，显示在“分单成交”里
//vector<commissionBusiness*>comMessage;//股票委托的信息，这些在设计交易算法里要用到）
QVector<commissionBusiness*>comofBuy;
QVector<commissionBusiness*>comofSell;

QVector<commissionBusiness*>BuyPriceList;
QVector<commissionBusiness*>SellPriceList;
*/



// 新股申购的函数如下

void stock::applytobuy(int applynumber,stockholder*applyholder)
{
    tobeBuy-=applynumber;
    bool hasa=false;
    for(int i=0;i<applyholder->holderStock.size();i++)
    {if(this->stockName==applyholder->holderStock[i]->stockName)
        {hasa=true;
            applyholder->holderStock[i]->positionNumber+=applynumber;
             applyholder->holderStock[i]->totalBuyValue+=this->initialPrice*applynumber;
              applyholder->holderStock[i]->totalCurrentValue= applyholder->holderStock[i]->totalBuyValue;
               applyholder->holderStock[i]->positionRate= applyholder->holderStock[i]->totalCurrentValue/applyholder->currentMoney;
        }
        break;
    }
   if(hasa==false)
       (applyholder->holderStock).push_back(new mystock(this->stockName,this->stockCode,this,applynumber,this->initialPrice,applyholder));

      applyholder->availableMoney-=applynumber*initialPrice;

}

/*bool canTrade;//被申购完，可以流通
//股票名称和代码和当前价格被继承
int totalStockNumber;//总股数
double initialPrice;//初始股价
 //以上是股票最基本信息，不会变

double currentTotalPrice;//流通总市值（区别于公司总值：都是×股数，但是公司总值是净资产*股数，这个是股价*股数。公司总值和
double raisingPrice;//涨值                 股票的交易没有关系，就取决于公司的利润，但是流通总值取决于股票的交易价格，即股民的
double raisingRate;//涨幅                   估值。具体可以回想以前学过的价值规律：价格围绕价值波动，受供求关系影响，公司总值
//这些是基于当前股价而变化的               和”finance.h里的净资产，都可以看成内在价格）

double priceEnd;//收盘价
double priceBegin;//开盘价
double highest;//今日最高
double lowest;//今日最低
double limitUp;//涨停线（就是今日开盘价*110%或120%）
double limitDown;//跌停线（今日开盘价*80%或90%）
int totalHandToday;//今日总交易手（交易总数量/100)
//这些都是对于这只股票每一天的数据，受当前股价一定的影响，这里显示的就是在表上显示的

double initialThisYear;//今年初始
double raisingRateYear;//今年涨幅
double historicalHighest;//历史最高
double historicalLowest;//历史最低

double realValue;// 每股净资产
double ROE;//净资产收益率（公司利润/净资产）
double PB;//市净率 （当前股价/每股净资产）
double EPS;//每股收益
double PER;//市盈率 （股票当前价格/每股收益）
company *thiscompany;
//这些和公司财务信息有关，有些就是公司财务信息里的值，copy过来*/
