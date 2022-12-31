#ifndef SIGN1_H
#define SIGN1_H

#include"stockholder.h"
#include <QWidget>
#include<widget.h>
#include<QVector>
#include"totalaccount.h"
#include"stockholder.h"
namespace Ui {
class sign1;
}

class sign1 : public QWidget//股东注册界面
{
    Q_OBJECT
    friend class Widget;
public:
    explicit sign1(Widget*,QWidget *parent = nullptr);
    ~sign1();
    stockholder*stockholderSign1;


    Widget*w;
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::sign1 *ui;

   QVector<stockholder*>vec1;

};

#endif // SIGN1_H
