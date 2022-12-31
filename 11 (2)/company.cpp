#include"company.h"
company::company(QString name,QString word,QString _stockname,finance*_firstfinance) {
    userName=name,password=word, stockname=_stockname,myFinance=_firstfinance;
}
void company::registerInf(int year,int month,double _profit){myFinance->modify( year, month,_profit);}

/*public:
    company();
    void registerInf();//公司更改财务信息，参数见界面

protected:
    QDateTime listTime;//上市时间，就记录公司账户成功注册的系统时间（意味着股票通过要求，可以上市）
    //公司名和密码继承username
    stock thisStock;//公司所注册的股票
    QVector<finance>myFinance;//公司每个月财务信息的向量数组  */
