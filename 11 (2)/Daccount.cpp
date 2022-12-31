#include "Daccount.h"
#include "ui_Daccount.h"
#include"holdshares.h"
#include"transactioninformation.h"
#include"transaction.h"
Account::Account(Widget*W,stockholder*st,QWidget *parent) :
    QMainWindow(parent),
    stockholderInDAccount(st),
    w(W),
    ui(new Ui::Account)
{
    ui->setupUi(this);
    stockholderInDAccount->modifyHolderMessage();
    setLabel();
}

Account::~Account()
{
    delete ui;
    stockholderInDAccount=nullptr;
}

void Account::on_pushButton_clicked()
{
    holdShares *holdShares1=new holdShares(stockholderInDAccount);
    holdShares1->show();
}

void Account::on_pushButton_2_clicked()
{
    transactionInformation *transactionInformation1=new transactionInformation(stockholderInDAccount);
    transactionInformation1->show();
}

void Account::on_pushButton_3_clicked()
{
    transaction *transaction1=new transaction(w,stockholderInDAccount);
    transaction1->show();
}

void Account::on_pushButton_4_clicked()
{
    this->close();
}



void Account::setLabel()//d
{

    ui->label->setText(QString::number(stockholderInDAccount->initialMoney,'f',2));
    ui->label_2->setText(QString::number(stockholderInDAccount->currentMoney,'f',2));
    ui->label_10->setText(stockholderInDAccount->holderType);
    ui->label_3->setText(QString::number(stockholderInDAccount->currentPositionPrice,'f',2));
    ui->label_4->setText(QString::number(stockholderInDAccount->availableMoney,'f',2));
    ui->label_6->setText(QString::number(stockholderInDAccount->totalEarning,'f',2));
    ui->label_7->setText(QString::number(stockholderInDAccount->todayEarning,'f',2));
    ui->label_8->setText(QString::number(stockholderInDAccount->earningRate*100,'f',2)+"%");
    ui->label_9->setText(stockholderInDAccount->userName);
}


void Account::on_pushButton_5_clicked()
{
    stockholderInDAccount->modifyHolderMessage();
    setLabel();
}
