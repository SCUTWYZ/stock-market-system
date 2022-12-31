#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include"stock.h"
#include"company.h"
#include"stockholder.h"
#include"candlestickdatareader.h"
#include"qsplineseries.h"
#include"qcandlestickseries.h"
#include"qchartview.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow//显示某只股票信息的核心界面类
{
    Q_OBJECT

public:
    MainWindow(Widget*w, stock*,stockholder*,QWidget *parent = nullptr);
    int chart();//显示与更新k线图



    ~MainWindow();


    void setLabel(stock*);//更新该界面显示的信息

    stock *stockInMainWindow;//不同于该类的私有成员，这些是用来代表该类显示的信息以及操作所属的股票，股东等对象，以及它的信息来源的初始widget,其它类的public成员亦是如此
    company *companyInMainWindow;
    stockholder*stockholderInMainWindow;
    Widget*w;

signals:
    void transactionShow();


private slots:


    void on_transAction_clicked();

    void on_pushButton_2_clicked();

    void on_Account_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();



    void on_comboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QChartView *chartView1;
    QChartView*chartView2;
};
#endif // MAINWINDOW_H
