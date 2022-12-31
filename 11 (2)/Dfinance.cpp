#include "Dfinance.h"
#include "ui_Dfinance.h"

Finance::Finance(company*co,QWidget *parent) :
    QMainWindow(parent),
    companyInFinance(co),
    ui(new Ui::Finance)

{
    ui->setupUi(this);
    setLabel();
}

Finance::~Finance()
{
    delete ui;
    companyInFinance=nullptr;
}
void Finance::setLabel()
{


    ui->label->setText(companyInFinance->userName);

    ui->label_2->setText(companyInFinance->stockname);

    //ui->label_3->setText(companyInFinance->listTime.toString());

    ui->label_7->setText(QString::number(companyInFinance->myFinance->profit,'f',2));

    ui->label_9->setText(QString::number(companyInFinance->myFinance->stockNumber,'f',2));

    ui->label_11->setText(QString::number(companyInFinance->myFinance->totalValue,'f',2));

    ui->label_13->setText(QString::number(companyInFinance->myFinance->stockinitialPrice,'f',2));

    ui->label_15->setText(QString::number(companyInFinance->myFinance->realValue,'f',2));

    ui->label_17->setText(QString::number(companyInFinance->myFinance->ROE*100,'f',2)+"%");

   ui->label_19->setText(QString::number(companyInFinance->myFinance->EPS,'f',2));

    ui->label_4->setText(QString::number(companyInFinance->myFinance->registerYear)+"年"+QString::number(companyInFinance->myFinance->registerMonth)+"月");

}

