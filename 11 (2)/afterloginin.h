#ifndef AFTERLOGININ_H
#define AFTERLOGININ_H

#include<totalclass.h>
#include <QMainWindow>
#include<QPushButton>
#include<stockholder.h>
#include"company.h"



namespace Ui { class afterLoginin; }


class afterLoginin : public QMainWindow//是登录后的主界面
{
    Q_OBJECT
friend class SubscriptionOfNewShares;


public:

afterLoginin(Widget*w,stockholder*a,QWidget *parent = nullptr);


    ~afterLoginin();

void setlabel();//用于显示主界面各股票的信息



    stockholder *stockholderInAfterloginin;
    Widget *w;
    QVector<stock*>canbuystock;

signals:
    void transactionShow();


private slots:


    void on_transAction_clicked();



    void on_Account_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();


   void on_pushButton_4_clicked();
     void on_pushButton_8_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();

   void on_pushButton_13_clicked();

private:
    Ui::afterLoginin *ui;



};
#endif // AFTERLOGININ_H
