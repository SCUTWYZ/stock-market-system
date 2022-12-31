#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"transaction.h"
#include"Dfinance.h"
#include"Daccount.h"
#include"pbmore.h"
#include<QString>

#include<QPushButton>
#include<iostream>
#include<QString>

#include"qsplineseries.h"
#include"candlestickdatareader.h"
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QCandlestickSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCore/QDateTime>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>




int MainWindow::chart(){
    ui->gridLayout_2->removeWidget(chartView1);
    QCandlestickSeries* acmeSeries = new QCandlestickSeries();
    acmeSeries->setName("");
    acmeSeries->setIncreasingColor(QColor(Qt::green));
    acmeSeries->setDecreasingColor(QColor(Qt::red));
    //! [1]


    QFile acmeData(":acme");
    if (!acmeData.open(QIODevice::ReadOnly | QIODevice::Text))
      return 1;

    QStringList categories;

    CandlestickDataReader dataReader(&acmeData);
    while (!dataReader.atEnd()) {
        QCandlestickSet *set = dataReader.readCandlestickSet();
        if (set) {
            acmeSeries->append(set);
            categories << QDateTime::fromMSecsSinceEpoch(set->timestamp()).toString("dd");
        }
    }
    //! [2]

    //! [3]
    QChart *chart = new QChart();
    chart->addSeries(acmeSeries);
    chart->setTitle("K线图");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    //! [3]

    //! [4]
    chart->createDefaultAxes();

    QBarCategoryAxis *axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(categories);

    QValueAxis *axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
    axisY->setMax(axisY->max() * 1.01);
    axisY->setMin(axisY->min() * 0.99);
    //! [4]

    //! [5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    //! [5]

    //! [6]
    //!
     chartView1 = new QChartView(chart);

    chartView1->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout_2->removeWidget(chartView2);
    ui->gridLayout_2->addWidget(chartView1);

}


MainWindow::MainWindow(Widget*w,stock *st,stockholder*sth,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->w=w;
    ui->setupUi(this);
    stockholderInMainWindow=sth;
    stockInMainWindow=st;
    stockInMainWindow->strike();
    stockInMainWindow->modifystockmessage(stockInMainWindow->currentPrice);
    stockInMainWindow->showbuyPriceList();
    stockInMainWindow->showsellPriceList();
    setLabel(stockInMainWindow);
    companyInMainWindow=stockInMainWindow->thisCompany;
    chart();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_transAction_clicked()//交易
{
    transaction *transaction1=new transaction(w,stockholderInMainWindow);
    transaction1->show();
}


void MainWindow::on_pushButton_2_clicked()//财务
{
    Finance *finance1=new Finance(companyInMainWindow);
    finance1->show();
}

void MainWindow::on_Account_clicked()//账户
{
    Account *account1=new Account(w,stockholderInMainWindow);
    account1->show();

}

void MainWindow::on_pushButton_clicked()
{
    pbmore *pbmore1=new pbmore(stockInMainWindow);
    pbmore1->show();
}
void MainWindow::setLabel(stock *st)
{
    stockInMainWindow=st;

    ui->label_4->setText(st->stockName);
    ui->label_5->setText(st->stockCode);
    ui->label_6->setText(QString::number(st->totalStockNumber,10));
    ui->label_8->setText(QString::number(st->currentPrice,'f',2));
    ui->label_10->setText(QString::number(st->raisingRate*100,'f',2)+"%");
    ui->label_12->setText(QString::number(st->raisingPrice,'f',2));
    ui->label_14->setText(QString::number(st->currentTotalPrice,'f',2));
    ui->label_16->setText(QString::number(st->priceBegin,'f',2));

    ui->label_20->setText(QString::number(st->limitUp,'f',2));
    ui->label_22->setText(QString::number(st->limitDown,'f',2));
    ui->label_24->setText(QString::number(st->highest,'f',2));
    ui->label_26->setText(QString::number(st->lowest,'f',2));


    if(st->raisingRate>=0)
    {
        ui->label_4->setStyleSheet("QLabel{color:red}");
        ui->label_5->setStyleSheet("QLabel{color:red}");
        ui->label_6->setStyleSheet("QLabel{color:red}");
        ui->label_8->setStyleSheet("QLabel{color:red}");
        ui->label_10->setStyleSheet("QLabel{color:red}");
        ui->label_12->setStyleSheet("QLabel{color:red}");
        ui->label_14->setStyleSheet("QLabel{color:red}");
        ui->label_16->setStyleSheet("QLabel{color:red}");
        ui->label_20->setStyleSheet("QLabel{color:red}");
        ui->label_22->setStyleSheet("QLabel{color:red}");
        ui->label_24->setStyleSheet("QLabel{color:red}");
        ui->label_26->setStyleSheet("QLabel{color:red}");
        ui->label->setStyleSheet("QLabel{color:red}");
        ui->label_2->setStyleSheet("QLabel{color:red}");
        ui->label_3->setStyleSheet("QLabel{color:red}");
        ui->label_7->setStyleSheet("QLabel{color:red}");
        ui->label_9->setStyleSheet("QLabel{color:red}");
        ui->label_11->setStyleSheet("QLabel{color:red}");
        ui->label_13->setStyleSheet("QLabel{color:red}");
        ui->label_15->setStyleSheet("QLabel{color:red}");
        ui->label_17->setStyleSheet("QLabel{color:red}");
        ui->label_18->setStyleSheet("QLabel{color:red}");
        ui->label_21->setStyleSheet("QLabel{color:red}");
        ui->label_23->setStyleSheet("QLabel{color:red}");
        ui->label_25->setStyleSheet("QLabel{color:red}");
    }
    else
    {
        ui->label_4->setStyleSheet("QLabel{color:green}");
        ui->label_5->setStyleSheet("QLabel{color:green}");
        ui->label_6->setStyleSheet("QLabel{color:green}");
        ui->label_8->setStyleSheet("QLabel{color:green}");
        ui->label_10->setStyleSheet("QLabel{color:green}");
        ui->label_12->setStyleSheet("QLabel{color:green}");
        ui->label_14->setStyleSheet("QLabel{color:green}");
        ui->label_16->setStyleSheet("QLabel{color:green}");
        ui->label_20->setStyleSheet("QLabel{color:green}");
        ui->label_22->setStyleSheet("QLabel{color:green}");
        ui->label_24->setStyleSheet("QLabel{color:green}");
        ui->label_26->setStyleSheet("QLabel{color:green}");
        ui->label->setStyleSheet("QLabel{color:green}");
        ui->label_2->setStyleSheet("QLabel{color:green}");
        ui->label_3->setStyleSheet("QLabel{color:green}");
        ui->label_7->setStyleSheet("QLabel{color:green}");
        ui->label_9->setStyleSheet("QLabel{color:green}");
        ui->label_11->setStyleSheet("QLabel{color:green}");
        ui->label_13->setStyleSheet("QLabel{color:green}");
        ui->label_15->setStyleSheet("QLabel{color:green}");
        ui->label_17->setStyleSheet("QLabel{color:green}");
        ui->label_18->setStyleSheet("QLabel{color:green}");
        ui->label_21->setStyleSheet("QLabel{color:green}");
        ui->label_23->setStyleSheet("QLabel{color:green}");
        ui->label_25->setStyleSheet("QLabel{color:green}");
    }
//价格
    if(st->SellPriceList.length()>=5)
    {
    ui->label_38->setText(QString::number(st->SellPriceList[4]->comPrice,'f',2));
    ui->label_40->setText(QString::number(st->SellPriceList[3]->comPrice,'f',2));
    ui->label_43->setText(QString::number(st->SellPriceList[2]->comPrice,'f',2));
    ui->label_44->setText(QString::number(st->SellPriceList[1]->comPrice,'f',2));
    ui->label_46->setText(QString::number(st->SellPriceList[0]->comPrice,'f',2));
    ui->label_39->setText(QString::number(st->SellPriceList[4]->comNumber/100,10));
    ui->label_51->setText(QString::number(st->SellPriceList[3]->comNumber/100,10));
    ui->label_30->setText(QString::number(st->SellPriceList[2]->comNumber/100,10));
    ui->label_45->setText(QString::number(st->SellPriceList[1]->comNumber/100,10));
    ui->label_50->setText(QString::number(st->SellPriceList[0]->comNumber/100,10));
    }
    if(st->SellPriceList.length()==4)
    {
        ui->label_40->setText(QString::number(st->SellPriceList[3]->comPrice,'f',2));
        ui->label_43->setText(QString::number(st->SellPriceList[2]->comPrice,'f',2));
        ui->label_44->setText(QString::number(st->SellPriceList[1]->comPrice,'f',2));
        ui->label_46->setText(QString::number(st->SellPriceList[0]->comPrice,'f',2));
        ui->label_51->setText(QString::number(st->SellPriceList[3]->comNumber/100,10));
        ui->label_30->setText(QString::number(st->SellPriceList[2]->comNumber/100,10));
        ui->label_45->setText(QString::number(st->SellPriceList[1]->comNumber/100,10));
        ui->label_50->setText(QString::number(st->SellPriceList[0]->comNumber/100,10));
    }
    if(st->SellPriceList.length()==3)
    {
        ui->label_43->setText(QString::number(st->SellPriceList[2]->comPrice,'f',2));
        ui->label_44->setText(QString::number(st->SellPriceList[1]->comPrice,'f',2));
        ui->label_46->setText(QString::number(st->SellPriceList[0]->comPrice,'f',2));
        ui->label_30->setText(QString::number(st->SellPriceList[2]->comNumber/100,10));
        ui->label_45->setText(QString::number(st->SellPriceList[1]->comNumber/100,10));
        ui->label_50->setText(QString::number(st->SellPriceList[0]->comNumber/100,10));
    }
    if(st->SellPriceList.length()==2)
    {
        ui->label_44->setText(QString::number(st->SellPriceList[1]->comPrice,'f',2));
        ui->label_46->setText(QString::number(st->SellPriceList[0]->comPrice,'f',2));
        ui->label_45->setText(QString::number(st->SellPriceList[1]->comNumber/100,10));
        ui->label_50->setText(QString::number(st->SellPriceList[0]->comNumber/100,10));
    }
    if(st->SellPriceList.length()==1)
    {
        ui->label_46->setText(QString::number(st->SellPriceList[0]->comPrice,'f',2));
        ui->label_50->setText(QString::number(st->SellPriceList[0]->comNumber/100,10));
    }

    if(st->BuyPriceList.length()>=5)
    {
        ui->label_47->setText(QString::number(st->BuyPriceList[0]->comPrice,'f',2));
        ui->label_48->setText(QString::number(st->BuyPriceList[1]->comPrice,'f',2));
        ui->label_49->setText(QString::number(st->BuyPriceList[2]->comPrice,'f',2));
        ui->label_52->setText(QString::number(st->BuyPriceList[3]->comPrice,'f',2));
        ui->label_53->setText(QString::number(st->BuyPriceList[4]->comPrice,'f',2));
        ui->label_58->setText(QString::number(st->BuyPriceList[0]->comNumber/100,10));
        ui->label_57->setText(QString::number(st->BuyPriceList[1]->comNumber/100,10));
        ui->label_56->setText(QString::number(st->BuyPriceList[2]->comNumber/100,10));
        ui->label_55->setText(QString::number(st->BuyPriceList[3]->comNumber/100,10));
        ui->label_54->setText(QString::number(st->BuyPriceList[4]->comNumber/100,10));
    }
    if(st->BuyPriceList.length()==4)
    {
        ui->label_47->setText(QString::number(st->BuyPriceList[0]->comPrice,'f',2));
        ui->label_48->setText(QString::number(st->BuyPriceList[1]->comPrice,'f',2));
        ui->label_49->setText(QString::number(st->BuyPriceList[2]->comPrice,'f',2));
        ui->label_52->setText(QString::number(st->BuyPriceList[3]->comPrice,'f',2));
        ui->label_58->setText(QString::number(st->BuyPriceList[0]->comNumber/100,10));
        ui->label_57->setText(QString::number(st->BuyPriceList[1]->comNumber/100,10));
        ui->label_56->setText(QString::number(st->BuyPriceList[2]->comNumber/100,10));
        ui->label_55->setText(QString::number(st->BuyPriceList[3]->comNumber/100,10));
    }
    if(st->BuyPriceList.length()==3)
    {
        ui->label_47->setText(QString::number(st->BuyPriceList[0]->comPrice,'f',2));
        ui->label_48->setText(QString::number(st->BuyPriceList[1]->comPrice,'f',2));
        ui->label_49->setText(QString::number(st->BuyPriceList[2]->comPrice,'f',2));
        ui->label_58->setText(QString::number(st->BuyPriceList[0]->comNumber/100,10));
        ui->label_57->setText(QString::number(st->BuyPriceList[1]->comNumber/100,10));
        ui->label_56->setText(QString::number(st->BuyPriceList[2]->comNumber/100,10));
    }
    if(st->BuyPriceList.length()==2)
    {
        ui->label_47->setText(QString::number(st->BuyPriceList[0]->comPrice,'f',2));
        ui->label_48->setText(QString::number(st->BuyPriceList[1]->comPrice,'f',2));
        ui->label_58->setText(QString::number(st->BuyPriceList[0]->comNumber/100,10));
        ui->label_57->setText(QString::number(st->BuyPriceList[1]->comNumber/100,10));
    }
   if(st->BuyPriceList.length()==1)
   {
       ui->label_47->setText(QString::number(st->BuyPriceList[0]->comPrice,'f',2));
       ui->label_58->setText(QString::number(st->BuyPriceList[0]->comNumber/100,10));
   }
    //分单成交价
     ui->textBrowser->clear();
    for(int i=0;i<st->businessMessage.length();i++)
    {

        ui->textBrowser->append(st->businessMessage[i]->tradingTime.toString()+" "+QString::number(st->businessMessage[i]->tradingPrice,'f',2)+" "+QString::number(st->businessMessage[i]->tradingNumber,'f',2));
    }

}

void MainWindow::on_pushButton_6_clicked()//退出登录
{

    this->close();
    w->show();
}

void MainWindow::on_pushButton_5_clicked()//返回主页
{
    afterLoginin *after=new afterLoginin(w,stockholderInMainWindow);
    this->close();
    after->show();
}

void MainWindow::on_pushButton_4_clicked()//刷新
{

    for(int i=0;i<10;i++)
    {int randint=rand()%10;
    if(randint<3)
    {    int index=rand()%w->allstockvec.size();
        double randprice=w->allstockvec[index]->currentPrice*(0.95+rand()%11/100);
        w->allholdervec[3]->buyStock(w->allstockvec[index],
                randprice>w->allstockvec[index]->limitDown&&
               randprice<w->allstockvec[index]->limitUp?
                    randprice:w->allstockvec[index]->limitUp,100);}
     if(randint>6)
     {
         int index=rand()%w->allstockvec.size();
         double randprice=w->allstockvec[index]->currentPrice*(0.95+rand()%11/100);
         w->allholdervec[3]->sellStock(w->allstockvec[index],
                 randprice>w->allstockvec[index]->limitDown&&
                randprice<w->allstockvec[index]->limitUp?
                     randprice:w->allstockvec[index]->limitUp,100);}

    stockInMainWindow->strike();
    stockInMainWindow->showbuyPriceList();
    stockInMainWindow->showsellPriceList();
    setLabel(stockInMainWindow);


}
}




void MainWindow::on_comboBox_activated(const QString &args)//更改图像
{
    if(args=="日K线图")
    {
        chart();}

    if (args=="实时股价")
    {ui->gridLayout_2->removeWidget(chartView1);
     ui->gridLayout->removeWidget((chartView2));
        QSplineSeries*series = new QSplineSeries();
          series->setName("实时股价");
          if(stockInMainWindow->businessMessage.size()>0)
          series->append((QTime::currentTime().hour()*3600+QTime::currentTime().minute()*60+QTime::currentTime().second())/60.0-4,stockInMainWindow->businessMessage[0]->tradingPrice);
          else
          series->append((QTime::currentTime().hour()*3600+QTime::currentTime().minute()*60+QTime::currentTime().second())/60.0-4,stockInMainWindow->currentPrice);

         for(int i=stockInMainWindow->businessMessage.size()-1;i>=0;i--)
      series->append((stockInMainWindow->businessMessage[i]->tradingTime.hour()*3600+
                      stockInMainWindow->businessMessage[i]->tradingTime.minute()*60+
                      stockInMainWindow->businessMessage[i]->tradingTime.second())/60.0
                        ,stockInMainWindow->businessMessage[i]->tradingPrice);
      series->append((QTime::currentTime().hour()*3600+QTime::currentTime().minute()*60+QTime::currentTime().second())/60.0,stockInMainWindow->currentPrice);

          QChart *chart = new QChart();
            chart->legend()->hide();
            chart->addSeries(series);
            chart->setTitle("实时股价");
            chart->createDefaultAxes();
            chart->axisY()->setRange(stockInMainWindow->priceBegin*0.7,stockInMainWindow->priceBegin*1.3);
            chart->axisX()->setRange((QTime::currentTime().hour()*3600+QTime::currentTime().minute()*60+QTime::currentTime().second())/60.0-4,(QTime::currentTime().hour()*3600+QTime::currentTime().minute()*60+QTime::currentTime().second())/60.0+1);
            chartView2 = new QChartView(chart);
            chartView2->setRenderHint(QPainter::Antialiasing);
            ui->gridLayout_2->addWidget(chartView2);
    }
}
