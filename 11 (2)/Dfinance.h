#ifndef DFINANCE_H
#define DFINANCE_H

#include <QMainWindow>
#include"company.h"
#include"stockholder.h"
namespace Ui {
class Finance;
}

class Finance : public QMainWindow//用于显示一个股票的财务信息的界面
{
    Q_OBJECT

public:
    explicit Finance(company*,QWidget *parent = nullptr);
    ~Finance();
    void setLabel();
    company *companyInFinance;



private:
    Ui::Finance *ui;
};

#endif // FINANCE_H
