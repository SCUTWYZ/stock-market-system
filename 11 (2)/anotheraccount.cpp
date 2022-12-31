#include "anotheraccount.h"
#include "ui_anotheraccount.h"

anotheraccount::anotheraccount(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::anotheraccount)
{
    ui->setupUi(this);
}

anotheraccount::~anotheraccount()
{
    delete ui;
}
