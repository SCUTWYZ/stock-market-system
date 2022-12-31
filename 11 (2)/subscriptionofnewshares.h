#ifndef SUBSCRIPTIONOFNEWSHARES_H
#define SUBSCRIPTIONOFNEWSHARES_H

#include <QMainWindow>
#include"stockholder.h"
#include"Dfinance.h"
#include"success.h"
namespace Ui {
class SubscriptionOfNewShares;
}

class SubscriptionOfNewShares : public QMainWindow//新股申购的界面
{
    Q_OBJECT

public:
    explicit SubscriptionOfNewShares(Widget*_w,stockholder*stkh, QWidget *parent = nullptr);
    ~SubscriptionOfNewShares();
    stockholder*stockholderInSubscriptionofnewshares;
    Widget*w;


private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void setlabel();//显示更新可申购股票的信息

private:
    Ui::SubscriptionOfNewShares *ui;
    vector<stock*>v1;
};

#endif // SUBSCRIPTIONOFNEWSHARES_H
