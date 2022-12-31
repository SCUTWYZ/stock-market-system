#ifndef DACCOUNT_H
#define DACCOUNT_H

#include <QMainWindow>
#include"stockholder.h"
namespace Ui {
class Account;
}

class Account : public QMainWindow //用于显示股东类的个人账户的界面
{
    Q_OBJECT

public:
    explicit Account(Widget*W, stockholder*,QWidget *parent = nullptr);
    ~Account();
    stockholder *stockholderInDAccount;
    Widget*w;

    void setLabel();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_5_clicked();

private:
    Ui::Account *ui;
};

#endif // ACCOUNT_H
