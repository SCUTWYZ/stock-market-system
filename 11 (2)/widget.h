    #ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<sign1.h>
#include<sign2.h>
#include"totalclass.h"
#include"stockholder.h"
#include"afterloginin.h"
#include"stock.h"
#include"company.h"
#include"subscriptionofnewshares.h"
#include"god.h"
#include"listedcompany.h"
#include<QDebug>
#include"mainPlateStock.h"
#include"innovationPlateStock.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget//开始界面，在这里储存原有的各种股票和股东公司，信息，也作为由这个类对象登录后所有界面的成员，可以修改这个类上储存的信息
{
    Q_OBJECT
friend class sign1;
friend class afterLoginin;
friend class transaction;
friend class SubscriptionOfNewShares;
friend class God;
friend class MainWindow;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    sign1 *s1;
    stockholder*stockholderInWidget;

    bool istrading;

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
   QVector<stockholder*>allholdervec;
   QVector<stock*>allstockvec;
   QVector<company*>allcompanyvec;


    //static QVector<stockholder> holdervec;
};
#endif // WIDGET_H
