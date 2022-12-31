#include "transactioninformation.h"
#include "ui_transactioninformation.h"

transactionInformation::transactionInformation(stockholder*st,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::transactionInformation)
{
    ui->setupUi(this);
    setTextBrowser(st);
}

transactionInformation::~transactionInformation()
{
    delete ui;
}
void transactionInformation::setTextBrowser(stockholder *st)
{

    stockholderInTransactionInformation=st;
    for(int i=0;i<st->holdercommission.length();i++)
    {   ui->textBrowser->append((st->holdercommission[i]->isbuy)==1?"买单":"卖单");
        ui->textBrowser->append("交易时间:"+st->holdercommission[i]->comTime.toString());
        ui->textBrowser->append(" 交易股票:"+st->holdercommission[i]->thisStock->stockName);
        ui->textBrowser->append(" 委托股数"+QString::number(st->holdercommission[i]->comNumber,'f',2)+" 委托价格:"+QString::number(st->holdercommission[i]->comPrice,'f',2));


    }
    for(int i=0;i<st->holderbusiness.length();i++)
    {   ui->textBrowser_2->append((st->holderbusiness[i]->buyHolder==st?"买入":"卖出"));
        ui->textBrowser_2->append("交易时间:"+st->holderbusiness[i]->tradingDate.toString()+" "+st->holderbusiness[i]->tradingTime.toString());
        ui->textBrowser_2->append(" 交易股票:"+st->holderbusiness[i]->tradingStock->stockName);
        ui->textBrowser_2->append(" 交易股数"+QString::number(st->holderbusiness[i]->tradingNumber,'f',2));
        ui->textBrowser_2->append(" 成交价格:"+QString::number(st->holderbusiness[i]->tradingPrice,'f',2)+"\n");
    }
}
/*stockholder *thisHolder;//这个单子的对象账户
bool isbuy;//是买单？（or卖单）
bool isComplete;//是否成交？还是未成交
stock *thisStock;//单子所委托交易的股票
int comNumber;//委托的股数（必须是100的倍数）
double comPrice;//委托的价格
QDateTime comTime;//委托的时间（因为相同的股票，相同的价格放在市场上，如果都符合成交条件，哪个先就哪个先成交）*/


/*QTime tradingTime;//这笔单子的成交时间
QDate tradingDate;//这笔单子的成交日
stock* tradingStock;//成交的股票
stockholder* soldHolder;//卖方账户
stockholder* buyHolder;//买方账户
int tradingNumber;//交易股数
double tradingPrice;//成交价格*/



