#ifndef HOLDSHARES_H
#define HOLDSHARES_H

#include <QMainWindow>
#include"stockholder.h"
namespace Ui {
class holdShares;
}

class holdShares : public QMainWindow//显示某个股东持仓界面
{
    Q_OBJECT

public:
    explicit holdShares(stockholder*,QWidget *parent = nullptr);
    ~holdShares();

    stockholder*stockholderInHolderShares;
    void setTextBrowser(stockholder*); //将持仓信息打印在框内
private:
    Ui::holdShares *ui;
};

#endif // HOLDSHARES_H
