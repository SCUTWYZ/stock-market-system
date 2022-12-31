#include "holdshares.h"
#include "ui_holdshares.h"

holdShares::holdShares(stockholder*st,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::holdShares)
{
    ui->setupUi(this);
    setTextBrowser(st);
}

holdShares::~holdShares()
{
    delete ui;
}
void holdShares::setTextBrowser(stockholder* st)
{
    ui->textBrowser->setText("股票名   持股数 买入价 买入总额 当前价 当前总额 盈亏 当日盈亏 持股比例   \n");
    for(int i=0;i<st->holderStock.length();i++)
    {
        ui->textBrowser->append(st->holderStock[i]->stockName +" "+QString::number(st->holderStock[i]->positionNumber,'f',2)+ " "+ QString::number(st->holderStock[i]->buyPrice,'f',2)+" "+ QString::number(st->holderStock[i]->totalBuyValue,'f',2) +"  "+QString::number(st->holderStock[i]->originStock->currentPrice,'f',2)+"  "+QString::number(st->holderStock[i]->totalCurrentValue,'f',2) +"  "+QString::number(st->holderStock[i]->earning,'f',2) +"  "+QString::number(st->holderStock[i]->earningToday,'f',2) +"  "+QString::number(st->holderStock[i]->positionRate*100,'f',2)+"%");

    }
}
/*int positionNumber;//持股数
double buyPrice;//买入价
double totalBuyValue;//买入总额（买入价*持股数）
double totalCurrentValue;//当前总额（股票当前价格*持股数
double earning;//盈亏=当前总额-买入总额
double todaybegin;//用来算下一个数据
double earningToday;//当日盈亏
double positionRate;//持股比例 = 当前总额/该账户的当前资金
stockholder* owningHolder;//该股票拥有者*/
