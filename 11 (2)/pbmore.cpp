#include "pbmore.h"
#include "ui_pbmore.h"

pbmore::pbmore(stock* st,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pbmore)
{
    ui->setupUi(this);
    setLabel(st);
}

pbmore::~pbmore()
{
    delete ui;
}
void pbmore::setLabel(stock *st)
{
    stockInPbmore=st;
    ui->label_3->setText(QString::number(st->totalRaisingRate*100,'f',2)+"%");
    ui->label_2->setText(QString::number(st->historicalHighest,'f',2));
    ui->label_7->setText(QString::number(st->historicalLowest,'f',2));
    ui->label_8->setText(QString::number(st->PER,'f',2));
    ui->label_10->setText(QString::number(st->PB,'f',2));
    ui->label_12->setText(QString::number(st->realValue,'f',2));
    ui->label_14->setText(QString::number(st->totalHandToday,'f',2));
    ui->label_17->setText(QString::number(st->ROE,'f',2));

    if(st->raisingRate>=0)
    {
        ui->label->setStyleSheet("QLabel{color:red}");
        ui->label_2->setStyleSheet("QLabel{color:red}");
        ui->label_3->setStyleSheet("QLabel{color:red}");
        ui->label_4->setStyleSheet("QLabel{color:red}");
        ui->label_5->setStyleSheet("QLabel{color:red}");
        ui->label_6->setStyleSheet("QLabel{color:red}");
        ui->label_7->setStyleSheet("QLabel{color:red}");
        ui->label_8->setStyleSheet("QLabel{color:red}");
        ui->label_9->setStyleSheet("QLabel{color:red}");
        ui->label_10->setStyleSheet("QLabel{color:red}");
        ui->label_11->setStyleSheet("QLabel{color:red}");
        ui->label_12->setStyleSheet("QLabel{color:red}");
        ui->label_13->setStyleSheet("QLabel{color:red}");
        ui->label_14->setStyleSheet("QLabel{color:red}");
        ui->label_15->setStyleSheet("QLabel{color:red}");
        ui->label_17->setStyleSheet("QLabel{color:red}");

    }
    else
    {
        ui->label->setStyleSheet("QLabel{color:green}");
        ui->label_2->setStyleSheet("QLabel{color:green}");
        ui->label_3->setStyleSheet("QLabel{color:green}");
        ui->label_4->setStyleSheet("QLabel{color:green}");
        ui->label_5->setStyleSheet("QLabel{color:green}");
        ui->label_6->setStyleSheet("QLabel{color:green}");
        ui->label_7->setStyleSheet("QLabel{color:green}");
        ui->label_8->setStyleSheet("QLabel{color:green}");
        ui->label_9->setStyleSheet("QLabel{color:green}");
        ui->label_10->setStyleSheet("QLabel{color:green}");
        ui->label_11->setStyleSheet("QLabel{color:green}");
        ui->label_12->setStyleSheet("QLabel{color:green}");
        ui->label_13->setStyleSheet("QLabel{color:green}");
        ui->label_14->setStyleSheet("QLabel{color:green}");
        ui->label_15->setStyleSheet("QLabel{color:green}");
        ui->label_17->setStyleSheet("QLabel{color:green}");
    }
}
