#ifndef ANOTHERACCOUNT_H
#define ANOTHERACCOUNT_H

#include <QMainWindow>
#include"stockholder.h"
namespace Ui {
class anotheraccount;
}

class anotheraccount : public QMainWindow
{
    Q_OBJECT

public:
    explicit anotheraccount(QWidget *parent = 0);
    ~anotheraccount();
    stockholder *stockholderInAnotheraccount;

private:
    Ui::anotheraccount *ui;
};

#endif // ANOTHERACCOUNT_H
