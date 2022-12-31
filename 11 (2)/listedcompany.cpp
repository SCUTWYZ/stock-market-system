#include "listedcompany.h"
#include "ui_listedcompany.h"

ListedCompany::ListedCompany(Widget*_w,company*thisc,QWidget *parent) :
    QMainWindow(parent),
    w(_w),
    thiscompany(thisc),
    ui(new Ui::ListedCompany)
{ui->setupUi(this);
ui->label_2->setText(QString::number(thiscompany->myFinance->registerYear)+"年"+QString::number(thiscompany->myFinance->registerMonth)+"月");
    ui->label_4->setText(QString::number(thiscompany->myFinance->profit,'f',2));
    ui->label_6->setText(QString::number(thiscompany->myFinance->realValue,'f',2));
    ui->label_8->setText(QString::number(thiscompany->myFinance->stockNumber,'f',2));
    ui->label_10->setText(QString::number(thiscompany->myFinance->ROE*100,'f',2)+"%");
    ui->label_12->setText(QString::number(thiscompany->myFinance->totalValue,'f',2));
    ui->label_16->setText(QString::number(thiscompany->myFinance->EPS,'f',2));
    ui->label_14->setText(QString::number(thiscompany->myFinance->stockinitialPrice,'f',2));
}

ListedCompany::~ListedCompany()
{
    delete ui;
    thiscompany=nullptr;
}

void ListedCompany::on_pushButton_clicked()//确定（退出登录）
{
    int pyear=ui->textEdit_3->document()->toPlainText().toInt();
    int pmonth=ui->textEdit_4->document()->toPlainText().toInt();
    double pprofit=ui->textEdit_5->document()->toPlainText().toInt();
    thiscompany->registerInf(pyear,pmonth,pprofit);
    this->close();
    w->show();
}
