#include "afterloginin.h"
#include "ui_afterloginin.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"transaction.h"
#include"Dfinance.h"
#include"Daccount.h"
#include"widget.h"
#include<QPushButton>
#include<iostream>
#include"anotheraccount.h"
#include"subscriptionofnewshares.h"

afterLoginin::afterLoginin(Widget*_w,stockholder *a,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::afterLoginin)
{
    ui->setupUi(this);
    stockholderInAfterloginin=a;
    w=_w;
    setlabel();
    stockholderInAfterloginin->modifyHolderMessage();
    ui->label->setText(w->istrading==true?"交易中":"休市中");
}




void afterLoginin::setlabel()
{   canbuystock.clear();
    for(int i=0;i<w->allstockvec.size();i++)

    {if(w->allstockvec[i]->tobeBuy==0)
            canbuystock.push_back(w->allstockvec[i]);}
    int allstocknumber=canbuystock.size();
                              //sort排序还没写
                                  //下面是数据可视化，把currentPrice,'g',6改成相应的数据即可

    //总览显示

    double a=0,b=0,c=0;
    for(int i=0;i<canbuystock.size();i++)
    {mainPlateStock*tempmain=dynamic_cast<mainPlateStock*>(canbuystock[i]);
     if(tempmain!=nullptr)
     {
         a+=tempmain->priceBegin*tempmain->totalStockNumber;
         b+=tempmain->currentPrice*tempmain->totalStockNumber;
     }
    }
    if (a!=0)
    ui->label_7->setText(QString::number(100*(b-a)/a,'f',2)+"%");
    else
     ui->label_7->setText(QString::number(0.00,'f',2)+"%");
    if(b>=a)
        ui->label_7->setStyleSheet("QLabel{color:red}");
    else
        ui->label_7->setStyleSheet("QLabel{color:green}");


     a=0,b=0,c=0;
    for(int i=0;i<canbuystock.size();i++)
    {innovationPlateStock*tempinno=dynamic_cast<innovationPlateStock*>(canbuystock[i]);
     if(tempinno!=nullptr)
     {
         a+=tempinno->priceBegin*tempinno->totalStockNumber;
         b+=tempinno->currentPrice*tempinno->totalStockNumber;
     }
    }
    if (a!=0)
    ui->label_8->setText(QString::number(100*(b-a)/a,'f',2)+"%");
    else
     ui->label_8->setText(QString::number(0.00,'f',2)+"%");
    if(b>=a)
        ui->label_8->setStyleSheet("QLabel{color:red}");
    else
        ui->label_8->setStyleSheet("QLabel{color:green}");


    double scuttotal=0;
    for(int i=0;i<canbuystock.size();i++)
        scuttotal+=canbuystock[i]->currentTotalPrice;
     ui->label_9->setText(QString::number(scuttotal,'f',0));


     double scutmain=0;
     for(int i=0;i<canbuystock.size();i++)
     {mainPlateStock*tempmain=dynamic_cast<mainPlateStock*>(canbuystock[i]);
      if(tempmain!=nullptr)
      {scutmain+=tempmain->currentTotalPrice;
      }
     }
     ui->label_10->setText(QString::number(scutmain,'f',0));


    double scutinno=0;
    for(int i=0;i<canbuystock.size();i++)
    {innovationPlateStock*tempinno=dynamic_cast<innovationPlateStock*>(canbuystock[i]);
     if(tempinno!=nullptr)
     {scutinno+=tempinno->currentTotalPrice;
     }
    }
    ui->label_11->setText(QString::number(scutinno,'f',0));






    //总览显示代码结束
                                  if(allstocknumber>=1)
                                 {
                                      ui->pushButton_4->setText(canbuystock[0]->stockName);

                                      ui->label_a11->setText(QString::number(canbuystock[0]->currentPrice,'f',2));

                                  ui->label_a12->setText(QString::number(canbuystock[0]->raisingRate*100,'f',2)+"%");

                                  ui->label_a13->setText(QString::number(canbuystock[0]->raisingPrice,'f',2));

                                  ui->label_a14->setText(QString::number(canbuystock[0]->currentTotalPrice,'f',0));

                                  ui->label_a15->setText(QString::number(canbuystock[0]->totalHandToday*100,'f',0));
                                  if(canbuystock[0]->raisingRate>=0)
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(255,0,0));
                                      ui->pushButton_4->setPalette(pal);
                                      ui->label_a11->setStyleSheet("QLabel{color:red}");
                                      ui->label_a12->setStyleSheet("QLabel{color:red}");
                                      ui->label_a13->setStyleSheet("QLabel{color:red}");
                                      ui->label_a14->setStyleSheet("QLabel{color:red}");
                                      ui->label_a15->setStyleSheet("QLabel{color:red}");
                                  }
                                  else
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(107,142,35));
                                      ui->pushButton_4->setPalette(pal);
                                      ui->label_a11->setStyleSheet("QLabel{color:green}");
                                      ui->label_a12->setStyleSheet("QLabel{color:green}");
                                      ui->label_a13->setStyleSheet("QLabel{color:green}");
                                      ui->label_a14->setStyleSheet("QLabel{color:green}");
                                      ui->label_a15->setStyleSheet("QLabel{color:green}");
                                  }

                                  }

                                  //
                                   if(allstocknumber>=2)
                                   {
                                        ui->pushButton_8->setText(canbuystock[1]->stockName);

                                  ui->label_a21->setText(QString::number(canbuystock[1]->currentPrice,'f',2));

                                  ui->label_a22->setText(QString::number(canbuystock[1]->raisingRate*100,'f',2)+"%");

                                  ui->label_a23->setText(QString::number(canbuystock[1]->raisingPrice,'f',2));

                                  ui->label_a24->setText(QString::number(canbuystock[1]->currentTotalPrice,'f',0));

                                  ui->label_a25->setText(QString::number(canbuystock[1]->totalHandToday*100,'f',0));
                                  if(canbuystock[1]->raisingRate>=0)
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(255,0,0));
                                      ui->pushButton_8->setPalette(pal);
                                      ui->label_a21->setStyleSheet("QLabel{color:red}");
                                      ui->label_a22->setStyleSheet("QLabel{color:red}");
                                      ui->label_a23->setStyleSheet("QLabel{color:red}");
                                      ui->label_a24->setStyleSheet("QLabel{color:red}");
                                      ui->label_a25->setStyleSheet("QLabel{color:red}");
                                  }
                                  else
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(107,142,35));
                                      ui->pushButton_8->setPalette(pal);
                                      ui->label_a21->setStyleSheet("QLabel{color:green}");
                                      ui->label_a22->setStyleSheet("QLabel{color:green}");
                                      ui->label_a23->setStyleSheet("QLabel{color:green}");
                                      ui->label_a24->setStyleSheet("QLabel{color:green}");
                                      ui->label_a25->setStyleSheet("QLabel{color:green}");
                                  }
                                   }

                                  //
                                   if(allstocknumber>=3)
                                   { ui->pushButton_2->setText(canbuystock[2]->stockName);

                                  ui->label_a31->setText(QString::number(canbuystock[2]->currentPrice,'f',2));

                                  ui->label_a32->setText(QString::number(canbuystock[2]->raisingRate*100,'f',2)+"%");

                                  ui->label_a33->setText(QString::number(canbuystock[2]->raisingPrice,'f',2));

                                  ui->label_a34->setText(QString::number(canbuystock[2]->currentTotalPrice,'f',0));

                                  ui->label_a35->setText(QString::number(canbuystock[2]->totalHandToday*100,'f',0));
                                  if(canbuystock[2]->raisingRate>=0)
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(255,0,0));
                                      ui->pushButton_2->setPalette(pal);
                                      ui->label_a31->setStyleSheet("QLabel{color:red}");
                                      ui->label_a32->setStyleSheet("QLabel{color:red}");
                                      ui->label_a33->setStyleSheet("QLabel{color:red}");
                                      ui->label_a34->setStyleSheet("QLabel{color:red}");
                                      ui->label_a35->setStyleSheet("QLabel{color:red}");
                                  }
                                  else
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(107,142,35));
                                      ui->pushButton_2->setPalette(pal);
                                      ui->label_a31->setStyleSheet("QLabel{color:green}");
                                      ui->label_a32->setStyleSheet("QLabel{color:green}");
                                      ui->label_a33->setStyleSheet("QLabel{color:green}");
                                      ui->label_a34->setStyleSheet("QLabel{color:green}");
                                      ui->label_a35->setStyleSheet("QLabel{color:green}");
                                  }
                                   }
                                  //
                                 if(allstocknumber>=4)
                                 {
                                     ui->pushButton_3->setText(canbuystock[3]->stockName);

                                  ui->label_a41->setText(QString::number(canbuystock[3]->currentPrice,'f',2));

                                  ui->label_a42->setText(QString::number(canbuystock[3]->raisingRate*100,'f',2)+"%");

                                  ui->label_a43->setText(QString::number(canbuystock[3]->raisingPrice,'f',2));

                                  ui->label_a44->setText(QString::number(canbuystock[3]->currentTotalPrice,'f',0));

                                  ui->label_a45->setText(QString::number(canbuystock[3]->totalHandToday*100,'f',0));
                                  if(canbuystock[3]->raisingRate>=0)
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(255,0,0));
                                      ui->pushButton_3->setPalette(pal);
                                      ui->label_a41->setStyleSheet("QLabel{color:red}");
                                      ui->label_a42->setStyleSheet("QLabel{color:red}");
                                      ui->label_a43->setStyleSheet("QLabel{color:red}");
                                      ui->label_a44->setStyleSheet("QLabel{color:red}");
                                      ui->label_a45->setStyleSheet("QLabel{color:red}");
                                  }
                                  else
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(107,142,35));
                                      ui->pushButton_3->setPalette(pal);
                                      ui->label_a41->setStyleSheet("QLabel{color:green}");
                                      ui->label_a42->setStyleSheet("QLabel{color:green}");
                                      ui->label_a43->setStyleSheet("QLabel{color:green}");
                                      ui->label_a44->setStyleSheet("QLabel{color:green}");
                                      ui->label_a45->setStyleSheet("QLabel{color:green}");
                                  }
                                 }
                                  //
                              if(allstocknumber>=5)
                                 {
                                  ui->pushButton_5->setText(canbuystock[4]->stockName);

                                  ui->label_a51->setText(QString::number(canbuystock[4]->currentPrice,'f',2));

                                  ui->label_a52->setText(QString::number(canbuystock[4]->raisingRate*100,'f',2)+"%");

                                  ui->label_a53->setText(QString::number(canbuystock[4]->raisingPrice,'f',2));

                                  ui->label_a54->setText(QString::number(canbuystock[4]->currentTotalPrice,'f',0));

                                  ui->label_a55->setText(QString::number(canbuystock[4]->totalHandToday*100,'f',0));
                                  if(canbuystock[4]->raisingRate>=0)
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(255,0,0));
                                      ui->pushButton_5->setPalette(pal);
                                      ui->label_a51->setStyleSheet("QLabel{color:red}");
                                      ui->label_a52->setStyleSheet("QLabel{color:red}");
                                      ui->label_a53->setStyleSheet("QLabel{color:red}");
                                      ui->label_a54->setStyleSheet("QLabel{color:red}");
                                      ui->label_a55->setStyleSheet("QLabel{color:red}");
                                  }
                                  else
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(107,142,35));
                                      ui->pushButton_5->setPalette(pal);
                                      ui->label_a51->setStyleSheet("QLabel{color:green}");
                                      ui->label_a52->setStyleSheet("QLabel{color:green}");
                                      ui->label_a53->setStyleSheet("QLabel{color:green}");
                                      ui->label_a54->setStyleSheet("QLabel{color:green}");
                                      ui->label_a55->setStyleSheet("QLabel{color:green}");
                                  }
                                  }
                                  //
                              if(allstocknumber>=6)

                              {
                                  ui->pushButton_7->setText(canbuystock[5]->stockName);

                                  ui->label_a61->setText(QString::number(canbuystock[5]->currentPrice,'f',2));

                                  ui->label_a62->setText(QString::number(canbuystock[5]->raisingRate*100,'f',2)+"%");

                                  ui->label_a63->setText(QString::number(canbuystock[5]->raisingPrice,'f',2));

                                  ui->label_a64->setText(QString::number(canbuystock[5]->currentTotalPrice,'f',0));

                                  ui->label_a65->setText(QString::number(canbuystock[5]->totalHandToday*100,'f',0));
                                  if(canbuystock[5]->raisingRate>=0)
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(255,0,0));
                                      ui->pushButton_7->setPalette(pal);
                                      ui->label_a61->setStyleSheet("QLabel{color:red}");
                                      ui->label_a62->setStyleSheet("QLabel{color:red}");
                                      ui->label_a63->setStyleSheet("QLabel{color:red}");
                                      ui->label_a64->setStyleSheet("QLabel{color:red}");
                                      ui->label_a65->setStyleSheet("QLabel{color:red}");
                                  }
                                  else
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(107,142,35));
                                      ui->pushButton_7->setPalette(pal);
                                      ui->label_a61->setStyleSheet("QLabel{color:green}");
                                      ui->label_a62->setStyleSheet("QLabel{color:green}");
                                      ui->label_a63->setStyleSheet("QLabel{color:green}");
                                      ui->label_a64->setStyleSheet("QLabel{color:green}");
                                      ui->label_a65->setStyleSheet("QLabel{color:green}");
                                  }
                                 }
                                  //
                              if(allstocknumber>=7)
                              {
                                  ui->pushButton_9->setText(canbuystock[6]->stockName);


                                  ui->label_a71->setText(QString::number(canbuystock[6]->currentPrice,'f',2));

                                  ui->label_a72->setText(QString::number(canbuystock[6]->raisingRate*100,'f',2)+"%");

                                  ui->label_a73->setText(QString::number(canbuystock[6]->raisingPrice,'f',2));

                                  ui->label_a74->setText(QString::number(canbuystock[6]->currentTotalPrice,'f',0));

                                  ui->label_a75->setText(QString::number(canbuystock[6]->totalHandToday*100,'f',0));
                                  if(canbuystock[6]->raisingRate>=0)
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(255,0,0));
                                      ui->pushButton_9->setPalette(pal);
                                      ui->label_a71->setStyleSheet("QLabel{color:red}");
                                      ui->label_a72->setStyleSheet("QLabel{color:red}");
                                      ui->label_a73->setStyleSheet("QLabel{color:red}");
                                      ui->label_a74->setStyleSheet("QLabel{color:red}");
                                      ui->label_a75->setStyleSheet("QLabel{color:red}");
                                  }
                                  else
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(107,142,35));
                                      ui->pushButton_9->setPalette(pal);
                                      ui->label_a71->setStyleSheet("QLabel{color:green}");
                                      ui->label_a72->setStyleSheet("QLabel{color:green}");
                                      ui->label_a73->setStyleSheet("QLabel{color:green}");
                                      ui->label_a74->setStyleSheet("QLabel{color:green}");
                                      ui->label_a75->setStyleSheet("QLabel{color:green}");
                                  }
                                 }
                                  //
                              if(allstocknumber>=8)
                              {
                                  ui->pushButton_10->setText(canbuystock[7]->stockName);

                                  ui->label_a81->setText(QString::number(canbuystock[7]->currentPrice,'f',2));

                                  ui->label_a82->setText(QString::number(canbuystock[7]->raisingRate*100,'f',2)+"%");

                                  ui->label_a83->setText(QString::number(canbuystock[7]->raisingPrice,'f',2));

                                  ui->label_a84->setText(QString::number(canbuystock[7]->currentTotalPrice,'f',0));

                                  ui->label_a85->setText(QString::number(canbuystock[7]->totalHandToday*100,'f',0));
                                  if(canbuystock[7]->raisingRate>=0)
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(255,0,0));
                                      ui->pushButton_10->setPalette(pal);
                                      ui->label_a81->setStyleSheet("QLabel{color:red}");
                                      ui->label_a82->setStyleSheet("QLabel{color:red}");
                                      ui->label_a83->setStyleSheet("QLabel{color:red}");
                                      ui->label_a84->setStyleSheet("QLabel{color:red}");
                                      ui->label_a85->setStyleSheet("QLabel{color:red}");
                                  }
                                  else
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(107,142,35));
                                      ui->pushButton_10->setPalette(pal);
                                      ui->label_a81->setStyleSheet("QLabel{color:green}");
                                      ui->label_a82->setStyleSheet("QLabel{color:green}");
                                      ui->label_a83->setStyleSheet("QLabel{color:green}");
                                      ui->label_a84->setStyleSheet("QLabel{color:green}");
                                      ui->label_a85->setStyleSheet("QLabel{color:green}");
                                  }
                              }
                                  //
                              if(allstocknumber>=9)
                              {
                                  ui->pushButton_11->setText(canbuystock[8]->stockName);

                                  ui->label_a91->setText(QString::number(canbuystock[8]->currentPrice,'f',2));

                                  ui->label_a92->setText(QString::number(canbuystock[8]->raisingRate*100,'f',2)+"%");

                                  ui->label_a93->setText(QString::number(canbuystock[8]->raisingPrice,'f',2));

                                  ui->label_a94->setText(QString::number(canbuystock[8]->currentTotalPrice,'f',0));

                                  ui->label_a95->setText(QString::number(canbuystock[8]->totalHandToday*100,'f',0));
                                  if(canbuystock[8]->raisingRate>=0)
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(255,0,0));
                                      ui->pushButton_11->setPalette(pal);
                                      ui->label_a91->setStyleSheet("QLabel{color:red}");
                                      ui->label_a92->setStyleSheet("QLabel{color:red}");
                                      ui->label_a93->setStyleSheet("QLabel{color:red}");
                                      ui->label_a94->setStyleSheet("QLabel{color:red}");
                                      ui->label_a95->setStyleSheet("QLabel{color:red}");
                                  }
                                  else
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(107,142,35));
                                      ui->pushButton_11->setPalette(pal);
                                      ui->label_a91->setStyleSheet("QLabel{color:green}");
                                      ui->label_a92->setStyleSheet("QLabel{color:green}");
                                      ui->label_a93->setStyleSheet("QLabel{color:green}");
                                      ui->label_a94->setStyleSheet("QLabel{color:green}");
                                      ui->label_a95->setStyleSheet("QLabel{color:green}");
                                  }
                               }
                                  //
                              if(allstocknumber>=10)
                              {
                                  ui->pushButton_12->setText(canbuystock[9]->stockName);

                                  ui->label_a101->setText(QString::number(canbuystock[9]->currentPrice,'f',2));

                                  ui->label_a102->setText(QString::number(canbuystock[9]->raisingRate*100,'f',2)+"%");

                                  ui->label_a103->setText(QString::number(canbuystock[9]->raisingPrice,'f',2));

                                  ui->label_a104->setText(QString::number(canbuystock[9]->currentTotalPrice,'f',0));

                                  ui->label_a105->setText(QString::number(canbuystock[9]->totalHandToday*100,'f',0));
                                  if(canbuystock[9]->raisingRate>=0)
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(255,0,0));
                                      ui->pushButton_12->setPalette(pal);
                                      ui->label_a101->setStyleSheet("QLabel{color:red}");
                                      ui->label_a102->setStyleSheet("QLabel{color:red}");
                                      ui->label_a103->setStyleSheet("QLabel{color:red}");
                                      ui->label_a104->setStyleSheet("QLabel{color:red}");
                                      ui->label_a105->setStyleSheet("QLabel{color:red}");
                                  }
                                  else
                                  {
                                      QPalette pal;
                                      pal.setColor(QPalette::ButtonText,QColor(107,142,35));
                                      ui->pushButton_12->setPalette(pal);
                                      ui->label_a101->setStyleSheet("QLabel{color:green}");
                                      ui->label_a102->setStyleSheet("QLabel{color:green}");
                                      ui->label_a103->setStyleSheet("QLabel{color:green}");
                                      ui->label_a104->setStyleSheet("QLabel{color:green}");
                                      ui->label_a105->setStyleSheet("QLabel{color:green}");
                                  }
                              }

}



void afterLoginin::on_Account_clicked()
{
    Account *anotheraccount1=new Account(w,stockholderInAfterloginin);
    anotheraccount1->show();
}

//

void afterLoginin::on_pushButton_4_clicked()//跳转核心界面
{
    setlabel();
    if(canbuystock.size()>=1)
   {
    MainWindow *newmainwindow=new MainWindow(w,canbuystock[0],stockholderInAfterloginin);
    this->close();
    newmainwindow->show();
    }
}

void afterLoginin::on_pushButton_8_clicked()
{setlabel();
    if(canbuystock.size()>=2)
   {
    MainWindow *newmainwindow=new MainWindow(w,canbuystock[1],stockholderInAfterloginin);
     this->close();
    newmainwindow->show();
    }
}

void afterLoginin::on_pushButton_2_clicked()
{setlabel();
    if(canbuystock.size()>=3)
   {
    MainWindow *newmainwindow=new MainWindow(w,canbuystock[2],stockholderInAfterloginin);
     this->close();
    newmainwindow->show();
    }
}

void afterLoginin::on_pushButton_3_clicked()
{setlabel();
    if(canbuystock.size()>=4)
   {
    MainWindow *newmainwindow=new MainWindow(w,canbuystock[3],stockholderInAfterloginin);
     this->close();
    newmainwindow->show();
    }
}

void afterLoginin::on_pushButton_5_clicked()
{setlabel();
    if(canbuystock.size()>=5)
   {
    MainWindow *newmainwindow=new MainWindow(w,canbuystock[4],stockholderInAfterloginin);
     this->close();
    newmainwindow->show();
    }
}

void afterLoginin::on_pushButton_7_clicked()
{setlabel();
    if(canbuystock.size()>=6)
   {
    MainWindow *newmainwindow=new MainWindow(w,canbuystock[5],stockholderInAfterloginin);
     this->close();
    newmainwindow->show();
    }
}

void afterLoginin::on_pushButton_9_clicked()
{setlabel();
    if(canbuystock.size()>=7)
   {
    MainWindow *newmainwindow=new MainWindow(w,canbuystock[6],stockholderInAfterloginin);
     this->close();
    newmainwindow->show();
    }
}

void afterLoginin::on_pushButton_10_clicked()
{setlabel();
    if(canbuystock.size()>=8)
   {
    MainWindow *newmainwindow=new MainWindow(w,canbuystock[7],stockholderInAfterloginin);
     this->close();
    newmainwindow->show();
    }
}

void afterLoginin::on_pushButton_11_clicked()
{setlabel();
    if(canbuystock.size()>=9)
   {
    MainWindow *newmainwindow=new MainWindow(w,canbuystock[8],stockholderInAfterloginin);
     this->close();
    newmainwindow->show();
    }
}

void afterLoginin::on_pushButton_12_clicked()
{setlabel();
    if(canbuystock.size()>=10)
   {
    MainWindow *newmainwindow=new MainWindow(w,canbuystock[9],stockholderInAfterloginin);
     this->close();
    newmainwindow->show();
    }
}

afterLoginin::~afterLoginin()
{
    delete ui;

    stockholderInAfterloginin=nullptr;
    w=nullptr;
    canbuystock.clear();


}


void afterLoginin::on_transAction_clicked()//交易
{
    transaction *transaction1=new transaction(w,stockholderInAfterloginin);
    transaction1->show();
}






void afterLoginin::on_pushButton_6_clicked()
{

    this->close();
    w->show();

    //几个“退出登录”都要保存数据
    //退出登录
}

void afterLoginin::on_pushButton_clicked()
{
    SubscriptionOfNewShares *subscriptionOfNewShares=new SubscriptionOfNewShares(w,stockholderInAfterloginin);
    subscriptionOfNewShares->show();
//新股申购
}



void afterLoginin::on_pushButton_13_clicked()
{
    //又一处人机代码
    for(int i=0;i<30;i++)
    {int randint=rand()%10;
    if(randint<3)
    {    int index=rand()%w->allstockvec.size();
        double randprice=w->allstockvec[index]->currentPrice*(0.97+rand()%7/100);
        w->allholdervec[3]->buyStock(w->allstockvec[index],
                randprice>w->allstockvec[index]->limitDown&&
               randprice<w->allstockvec[index]->limitUp?
                    randprice:w->allstockvec[index]->limitUp,100);}
     if(randint>6)
     {
         int index=rand()%w->allstockvec.size();
         double randprice=w->allstockvec[index]->currentPrice*(0.97+rand()%7/100);

         for(int i=0;i<w->allholdervec[3]->holderStock.size();i++)
         {if(w->allholdervec[3]->holderStock[i]->stockName==w->allstockvec[index]->stockName&&w->allholdervec[3]->holderStock[i]->positionNumber!=0)
         w->allholdervec[3]->sellStock(w->allstockvec[index],
                 randprice>w->allstockvec[index]->limitDown&&
                randprice<w->allstockvec[index]->limitUp?
                     randprice:w->allstockvec[index]->limitUp,100);}}}

    //人机代码结束
    for(int i=0;i<canbuystock.size();i++)
        canbuystock[i]->strike();
    setlabel();

}
