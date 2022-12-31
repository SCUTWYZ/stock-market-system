#include "subscriptionofnewshares.h"
#include "ui_subscriptionofnewshares.h"
#include<QFlags>
#include<QLabel>
SubscriptionOfNewShares::SubscriptionOfNewShares(Widget*_w,stockholder*holder,QWidget *parent) :
    QMainWindow(parent),
    stockholderInSubscriptionofnewshares(holder),
    w(_w),
    ui(new Ui::SubscriptionOfNewShares)
{
    ui->setupUi(this);

    setlabel();
}



void SubscriptionOfNewShares::setlabel()
{
  v1.clear();
for(int n=0;n<w->allstockvec.size();n++)
{
   if(w->allstockvec[n]->tobeBuy>0)
       v1.push_back(w->allstockvec[n]);
}


if(v1.size()==1)
{
   ui->label_5->setText(v1[0]->stockName);
ui->label_6->setText(QString::number(v1[0]->currentPrice));
ui->label_7->setText(QString::number(v1[0]->tobeBuy));
}

if(v1.size()==2)
{
    ui->label_5->setText(v1[0]->stockName);
   ui->label_6->setText(QString::number(v1[0]->currentPrice,'g',12));
   ui->label_7->setText(QString::number(v1[0]->tobeBuy,'g',12));
   ui->label_8->setText(v1[1]->stockName);
   ui->label_9->setText(QString::number(v1[1]->currentPrice,'g',12));
   ui->label_10->setText(QString::number(v1[1]->tobeBuy,'g',12));

}


if(v1.size()==3)
{
    ui->label_5->setText(v1[0]->stockName);
   ui->label_6->setText(QString::number(v1[0]->currentPrice,'g',12));
   ui->label_7->setText(QString::number(v1[0]->tobeBuy,'g',12));
   ui->label_8->setText(v1[1]->stockName);
   ui->label_9->setText(QString::number(v1[1]->currentPrice,'g',12));
   ui->label_10->setText(QString::number(v1[1]->tobeBuy,'g',12));
   ui->label_11->setText(v1[2]->stockName);
   ui->label_12->setText(QString::number(v1[2]->currentPrice,'g',12));
   ui->label_13->setText(QString::number(v1[2]->tobeBuy,'g',12));

}

if(v1.size()==4)
{
    ui->label_5->setText(v1[0]->stockName);
   ui->label_6->setText(QString::number(v1[0]->currentPrice,'g',12));
   ui->label_7->setText(QString::number(v1[0]->tobeBuy,'g',12));
   ui->label_8->setText(v1[1]->stockName);
   ui->label_9->setText(QString::number(v1[1]->currentPrice,'g',12));
   ui->label_10->setText(QString::number(v1[1]->tobeBuy,'g',12));
   ui->label_11->setText(v1[2]->stockName);
   ui->label_12->setText(QString::number(v1[2]->currentPrice,'g',12));
   ui->label_13->setText(QString::number(v1[2]->tobeBuy,'g',12));
   ui->label_14->setText(v1[3]->stockName);
   ui->label_15->setText(QString::number(v1[3]->currentPrice,'g',12));
   ui->label_16->setText(QString::number(v1[3]->tobeBuy,'g',12));

}




if(v1.size()==5)
{
    ui->label_5->setText(v1[0]->stockName);
   ui->label_6->setText(QString::number(v1[0]->currentPrice,'g',12));
   ui->label_7->setText(QString::number(v1[0]->tobeBuy,'g',12));
   ui->label_8->setText(v1[1]->stockName);
   ui->label_9->setText(QString::number(v1[1]->currentPrice,'g',12));
   ui->label_10->setText(QString::number(v1[1]->tobeBuy,'g',12));
   ui->label_11->setText(v1[2]->stockName);
   ui->label_12->setText(QString::number(v1[2]->currentPrice,'g',12));
   ui->label_13->setText(QString::number(v1[2]->tobeBuy,'g',12));
   ui->label_14->setText(v1[3]->stockName);
   ui->label_15->setText(QString::number(v1[3]->currentPrice,'g',12));
   ui->label_16->setText(QString::number(v1[3]->tobeBuy,'g',12));
   ui->label_17->setText(v1[4]->stockName);
   ui->label_18->setText(QString::number(v1[4]->currentPrice,'g',12));
   ui->label_19->setText(QString::number(v1[4]->tobeBuy,'g',12));

}


if(v1.size()==6)
{
    ui->label_5->setText(v1[0]->stockName);
   ui->label_6->setText(QString::number(v1[0]->currentPrice,'g',12));
   ui->label_7->setText(QString::number(v1[0]->tobeBuy,'g',12));
   ui->label_8->setText(v1[1]->stockName);
   ui->label_9->setText(QString::number(v1[1]->currentPrice,'g',12));
   ui->label_10->setText(QString::number(v1[1]->tobeBuy,'g',12));
   ui->label_11->setText(v1[2]->stockName);
   ui->label_12->setText(QString::number(v1[2]->currentPrice,'g',12));
   ui->label_13->setText(QString::number(v1[2]->tobeBuy,'g',12));
   ui->label_14->setText(v1[3]->stockName);
   ui->label_15->setText(QString::number(v1[3]->currentPrice,'g',12));
   ui->label_16->setText(QString::number(v1[3]->tobeBuy,'g',12));
   ui->label_17->setText(v1[4]->stockName);
   ui->label_18->setText(QString::number(v1[4]->currentPrice,'g',12));
   ui->label_19->setText(QString::number(v1[4]->tobeBuy,'g',12));
   ui->label_20->setText(v1[5]->stockName);
   ui->label_21->setText(QString::number(v1[5]->currentPrice,'g',12));
   ui->label_22->setText(QString::number(v1[5]->tobeBuy,'g',12));

}


if(v1.size()==7)
{
    ui->label_5->setText(v1[0]->stockName);
   ui->label_6->setText(QString::number(v1[0]->currentPrice,'g',12));
   ui->label_7->setText(QString::number(v1[0]->tobeBuy,'g',12));
   ui->label_8->setText(v1[1]->stockName);
   ui->label_9->setText(QString::number(v1[1]->currentPrice,'g',12));
   ui->label_10->setText(QString::number(v1[1]->tobeBuy,'g',12));
   ui->label_11->setText(v1[2]->stockName);
   ui->label_12->setText(QString::number(v1[2]->currentPrice,'g',12));
   ui->label_13->setText(QString::number(v1[2]->tobeBuy,'g',12));
   ui->label_14->setText(v1[3]->stockName);
   ui->label_15->setText(QString::number(v1[3]->currentPrice,'g',12));
   ui->label_16->setText(QString::number(v1[3]->tobeBuy,'g',12));
   ui->label_17->setText(v1[4]->stockName);
   ui->label_18->setText(QString::number(v1[4]->currentPrice,'g',12));
   ui->label_19->setText(QString::number(v1[4]->tobeBuy,'g',12));
   ui->label_20->setText(v1[5]->stockName);
   ui->label_21->setText(QString::number(v1[5]->currentPrice,'g',12));
   ui->label_22->setText(QString::number(v1[5]->tobeBuy,'g',12));
   ui->label_23->setText(v1[6]->stockName);
   ui->label_24->setText(QString::number(v1[6]->currentPrice,'g',12));
   ui->label_25->setText(QString::number(v1[6]->tobeBuy,'g',12));


}
if(v1.size()>7)
{
    ui->label_5->setText(v1[0]->stockName);
   ui->label_6->setText(QString::number(v1[0]->currentPrice,'g',12));
   ui->label_7->setText(QString::number(v1[0]->tobeBuy,'g',12));
   ui->label_8->setText(v1[1]->stockName);
   ui->label_9->setText(QString::number(v1[1]->currentPrice,'g',12));
   ui->label_10->setText(QString::number(v1[1]->tobeBuy,'g',12));
   ui->label_11->setText(v1[2]->stockName);
   ui->label_12->setText(QString::number(v1[2]->currentPrice,'g',12));
   ui->label_13->setText(QString::number(v1[2]->tobeBuy,'g',12));
   ui->label_14->setText(v1[3]->stockName);
   ui->label_15->setText(QString::number(v1[3]->currentPrice,'g',12));
   ui->label_16->setText(QString::number(v1[3]->tobeBuy,'g',12));
   ui->label_17->setText(v1[4]->stockName);
   ui->label_18->setText(QString::number(v1[4]->currentPrice,'g',12));
   ui->label_19->setText(QString::number(v1[4]->tobeBuy,'g',12));
   ui->label_20->setText(v1[5]->stockName);
   ui->label_21->setText(QString::number(v1[5]->currentPrice,'g',12));
   ui->label_22->setText(QString::number(v1[5]->tobeBuy,'g',12));
   ui->label_23->setText(v1[6]->stockName);
   ui->label_24->setText(QString::number(v1[6]->currentPrice,'g',12));
   ui->label_25->setText(QString::number(v1[6]->tobeBuy,'g',12));
   ui->label_26->setText(v1[7]->stockName);
   ui->label_27->setText(QString::number(v1[7]->currentPrice,'g',12));
   ui->label_28->setText(QString::number(v1[7]->tobeBuy,'g',12));
}
}

SubscriptionOfNewShares::~SubscriptionOfNewShares()
{
    delete ui;
    v1.clear();

}

void SubscriptionOfNewShares::on_pushButton_clicked()//财务按钮
{
    if(v1.size()>0)
    {
    Finance*thisfinance=new Finance(v1[0]->thisCompany);
    thisfinance->show();
    }
}

void SubscriptionOfNewShares::on_pushButton_3_clicked()//财务按钮
{
    if(v1.size()>1)
    {
    Finance*thisfinance=new Finance(v1[1]->thisCompany);
    thisfinance->show();
    }
}

void SubscriptionOfNewShares::on_pushButton_5_clicked()//财务按钮
{
    if(v1.size()>2)
    {
    Finance*thisfinance=new Finance(v1[2]->thisCompany);
    thisfinance->show();
    }
}

void SubscriptionOfNewShares::on_pushButton_7_clicked()//财务按钮
{
    if(v1.size()>3)
    {
    Finance*thisfinance=new Finance(v1[3]->thisCompany);
    thisfinance->show();
    }
}
void SubscriptionOfNewShares::on_pushButton_9_clicked()//财务按钮
{
    if(v1.size()>4)
    {
    Finance*thisfinance=new Finance(v1[4]->thisCompany);
    thisfinance->show();
    }
}
void SubscriptionOfNewShares::on_pushButton_11_clicked()//财务按钮
{
    if(v1.size()>5)
    {
    Finance*thisfinance=new Finance(v1[5]->thisCompany);
    thisfinance->show();
    }
}
void SubscriptionOfNewShares::on_pushButton_13_clicked()//财务按钮
{
    if(v1.size()>6)
    {
    Finance*thisfinance=new Finance(v1[6]->thisCompany);
    thisfinance->show();
    }
}
void SubscriptionOfNewShares::on_pushButton_15_clicked()//财务按钮
{
    if(v1.size()>7)
    {
    Finance*thisfinance=new Finance(v1[7]->thisCompany);
    thisfinance->show();
    }
}

void SubscriptionOfNewShares::on_pushButton_2_clicked()//购买按钮
{
    if(v1.size()>0)
    {
    int subnumber=ui->lineEdit->text().toInt();
    if(v1.size()>=1&&subnumber%100==0&&subnumber*v1[0]->initialPrice<=stockholderInSubscriptionofnewshares->availableMoney&&subnumber<=v1[0]->tobeBuy)
    {v1[0]->applytobuy(subnumber,stockholderInSubscriptionofnewshares);
        if(v1[0]->tobeBuy==0&&w->istrading==1)
            v1[0]->switchtoTrade();
          success *newsuccess=new success();
        newsuccess->show();}
    }
}

void SubscriptionOfNewShares::on_pushButton_4_clicked()//购买按钮
{
    if(v1.size()>1)
    {
    int subnumber=ui->lineEdit->text().toInt();
    if(v1.size()>=1&&subnumber%100==0&&subnumber*v1[1]->initialPrice<=stockholderInSubscriptionofnewshares->availableMoney&&subnumber<=v1[1]->tobeBuy)
    {v1[1]->applytobuy(subnumber,stockholderInSubscriptionofnewshares);
        if(v1[1]->tobeBuy==0&&w->istrading==1)
            v1[1]->switchtoTrade();
        success *newsuccess=new success();
        newsuccess->show();}
    }
}


void SubscriptionOfNewShares::on_pushButton_6_clicked()//购买按钮
{
    if(v1.size()>2)
    {
    int subnumber=ui->lineEdit->text().toInt();
    if(v1.size()>=1&&subnumber%100==0&&subnumber*v1[2]->initialPrice<=stockholderInSubscriptionofnewshares->availableMoney&&subnumber<=v1[2]->tobeBuy)
    {v1[2]->applytobuy(subnumber,stockholderInSubscriptionofnewshares);
        if(v1[2]->tobeBuy==0&&w->istrading==1)
            v1[2]->switchtoTrade();
        success *newsuccess=new success();
        newsuccess->show();}
    }
}


void SubscriptionOfNewShares::on_pushButton_8_clicked()//购买按钮
{
    if(v1.size()>3)
    {
    int subnumber=ui->lineEdit->text().toInt();
    if(v1.size()>=1&&subnumber%100==0&&subnumber*v1[3]->initialPrice<=stockholderInSubscriptionofnewshares->availableMoney&&subnumber<=v1[3]->tobeBuy)
    {v1[3]->applytobuy(subnumber,stockholderInSubscriptionofnewshares);
        if(v1[3]->tobeBuy==0&&w->istrading==1)
            v1[3]->switchtoTrade();
        success *newsuccess=new success();
        newsuccess->show();}
    }
}


void SubscriptionOfNewShares::on_pushButton_10_clicked()//购买按钮
{
    if(v1.size()>4)
    {
    int subnumber=ui->lineEdit->text().toInt();
    if(v1.size()>=1&&subnumber%100==0&&subnumber*v1[4]->initialPrice<=stockholderInSubscriptionofnewshares->availableMoney&&subnumber<=v1[4]->tobeBuy)
    {v1[4]->applytobuy(subnumber,stockholderInSubscriptionofnewshares);
        if(v1[4]->tobeBuy==0&&w->istrading==1)
            v1[4]->switchtoTrade();
        success *newsuccess=new success();
        newsuccess->show();}
    }
}


void SubscriptionOfNewShares::on_pushButton_12_clicked()//购买按钮
{
    if(v1.size()>5)
    {
    int subnumber=ui->lineEdit->text().toInt();
    if(v1.size()>=1&&subnumber%100==0&&subnumber*v1[5]->initialPrice<=stockholderInSubscriptionofnewshares->availableMoney&&subnumber<=v1[5]->tobeBuy)
    {v1[5]->applytobuy(subnumber,stockholderInSubscriptionofnewshares);
        if(v1[5]->tobeBuy==0&&w->istrading==1)
            v1[5]->switchtoTrade();
        success *newsuccess=new success();
        newsuccess->show();}
    }
}


void SubscriptionOfNewShares::on_pushButton_14_clicked()//购买按钮
{
    if(v1.size()>6)
    {
    int subnumber=ui->lineEdit->text().toInt();
    if(v1.size()>=1&&subnumber%100==0&&subnumber*v1[6]->initialPrice<=stockholderInSubscriptionofnewshares->availableMoney&&subnumber<=v1[6]->tobeBuy)
    {v1[6]->applytobuy(subnumber,stockholderInSubscriptionofnewshares);
        if(v1[6]->tobeBuy==0&&w->istrading==1)
            v1[6]->switchtoTrade();
        success *newsuccess=new success();
        newsuccess->show();}
    }
}


void SubscriptionOfNewShares::on_pushButton_16_clicked()//购买按钮
{
    if(v1.size()>7)
    {
    int subnumber=ui->lineEdit->text().toInt();
    if(v1.size()>=1&&subnumber%100==0&&subnumber*v1[7]->initialPrice<=stockholderInSubscriptionofnewshares->availableMoney&&subnumber<=v1[7]->tobeBuy)
    {v1[7]->applytobuy(subnumber,stockholderInSubscriptionofnewshares);
        if(v1[7]->tobeBuy==0&&w->istrading==1)
            v1[7]->switchtoTrade();
        success *newsuccess=new success();
        newsuccess->show();}
    }
}


void SubscriptionOfNewShares::on_pushButton_17_clicked()
{
     setlabel();
}
