#pragma once
//定义股票基类
#ifndef STOCK_H
#define STOCK_H
#include<string>
#include<vector>
#include"stockholder.h"
#include"stockbase.h"
#include"plate.h"
#include"business.h"
#include"stockPerDay.h"
#include"commissionBusiness.h"
#include"totalclass.h"
#include"company.h"
#include"transaction.h"
using namespace std;


class stock :public stockbase{//最核心最终要的类，储存一支市场上流通的股票的所有信息，以及进行对它的操作
	friend class mystock;
	friend class stockholder;
    friend class commissionBusiness;
    friend class MainWindow;
    friend class pbmore;
    friend class afterLoginin;
    friend class SubscriptionOfNewShares;
    friend class transaction;
    friend class God;
public:
    stock(company*);

    void modifystockmessage(double newPrice);//股票价格变动后，改变其一系列的相关数据

    void switchtoTrade();//转变为可交易

    virtual void beginTrade()=0;//重写实现多态，继承mainPlateStock,innovationPlateStock,这个函数在开盘的时候调用，更新开盘价和涨跌幅信息，两个板块的涨跌幅不同

    void endTrade();//结束交易，休市，并记录当天的股票信息于stockPerDay中

    bool cantrade();//返回是否可交易的值
	
	
    //下面是最核心的代码算法 ！！！！！！！！！！！！！！！！1（成交）
	//第一步 按照一定条件先分类遍历排序查找所有的委托单子
	//第二步 显示 打印 盘口信息
    //第三步  达成交易（比如 只要有新的委托单，点击各种刷新产生就调用一次这个函数 或者过几秒就调用一次）
	//第四步 判断交易成功后 生成新的business对象并添加到vector 更新股价和其它一系列信息 包括stockholder的信息
	/*细分步骤：
	* 1 某一刻的所有委托信息分成两类，首先对价格排序，同一价格对时间排序（价格分别升序和降序），
	  2.选择前五个价格，统计相应的手数，打印到盘口
	* 3..对买方的委托对象执行算法：仅仅参考其价格，对第一个卖单和第一个买单，如价格<=买单，则成交这笔交易，交易数量为对应买卖单中最小的，生成的这笔创建一个business对象，显示出来）
	* （每生成一个business就相应更改各种股票的基本信息，板块的基本信息等等）
	* 4..如果委托数量不相同，则修改成交但没完全成交的买卖单信息的委托股数为一个新的委托单，数量完全成交的从vector里去除，把后面的单往前移，生成新的vector，继续从第二步执行，直到没有交易为止
	* 5.如果新产生了一个委托单，就调用一次这个函数
	*/
    void strike();//最核心最核心的股票交易算法，内容庞大，每次成功交易后，还要调用stockholder，mystock，stock等类的modify函数去实施修改信息

    void showbuyPriceList();//更新买盘价

    void showsellPriceList();//更新卖盘价

    void applytobuy(int applynumber,stockholder*applyholder);//对这支股票新股申购
	
	//核心算法完成




    static bool GreaterSort (commissionBusiness*a,commissionBusiness*b) ;//这两个用于对股票类排序
    static bool LessSort (commissionBusiness*a,commissionBusiness*b) ;

	
protected:
    //关于申购
    bool canTrade;//被申购完，可以流通
    int tobeBuy;//剩余未购买股数



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
	
    double totalRaisingRate;//总涨幅
	double historicalHighest;//历史最高
	double historicalLowest;//历史最低
	
	double realValue;// 每股净资产
	double ROE;//净资产收益率（公司利润/净资产）
	double PB;//市净率 （当前股价/每股净资产）
	double EPS;//每股收益
	double PER;//市盈率 （股票当前价格/每股收益）
    company *thisCompany;
	//这些和公司财务信息有关，有些就是公司财务信息里的值，copy过来
	
    //plate plate1;//行业板块
    //plate stockType;//交易所+板块

	//交易信息和盘口信息等等
    QVector<stockPerDay*>dayMessage;//每天的信息
    QVector<business*>businessMessage;//画分时成交量图要用到里面的数据，是某个股票已成交的信息，显示在“分单成交”里
    //vector<commissionBusiness*>comMessage;//股票委托的信息，这些在设计交易算法里要用到）
    QVector<commissionBusiness*>comofBuy;
    QVector<commissionBusiness*>comofSell;

    QVector<commissionBusiness*>BuyPriceList;
    QVector<commissionBusiness*>SellPriceList;
	//关于后面（直接在	qt 里加），还要再加一系列的chart 类作为stock类的组成，为了作分时图象，可能还要外加一个“stockPerSecond"或者其它以秒或分钟为单位的股票信息类）也可能不用
	
};

#endif



#pragma once
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
#endif // !INNOVATIONPLATESTOCK_H


#pragma once
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
#endif // !MAINPLATESTOCK_H


