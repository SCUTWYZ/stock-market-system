#ifndef PBMORE_H
#define PBMORE_H

#include <QMainWindow>
#include"stock.h"
#include"stockholder.h"
namespace Ui {
class pbmore;
}

class pbmore : public QMainWindow//点开”更多“显示的其它股票相关财务信息
{
    Q_OBJECT

public:
    explicit pbmore(stock*,QWidget *parent = nullptr);
    ~pbmore();
    stock*stockInPbmore;
    stockholder*stockholderInPbmore;
    void setLabel(stock*);

private:
    Ui::pbmore *ui;
};

#endif // PBMORE_H
