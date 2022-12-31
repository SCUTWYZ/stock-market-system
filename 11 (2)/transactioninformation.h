#ifndef TRANSACTIONINFORMATION_H
#define TRANSACTIONINFORMATION_H

#include <QMainWindow>
#include"stockholder.h"
namespace Ui {
class transactionInformation;
}

class transactionInformation : public QMainWindow//显示某个账户的交易信息的界面
{
    Q_OBJECT

public:
    explicit transactionInformation(stockholder*,QWidget *parent = nullptr);
    ~transactionInformation();
    stockholder*stockholderInTransactionInformation;
    void setTextBrowser(stockholder*);


private slots:


private:
    Ui::transactionInformation *ui;
    int number;
};

#endif // TRANSACTIONINFORMATION_H
