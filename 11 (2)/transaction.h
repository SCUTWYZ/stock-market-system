#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QMainWindow>
#include"stockholder.h"
#include"widget.h"
namespace Ui {
class transaction;
}

class transaction : public QMainWindow//交易界面
{
    Q_OBJECT

public:
    explicit transaction(Widget*w,stockholder *_stockholderInTransaction,QWidget *parent = nullptr);
    ~transaction();
    stockholder *stockholderInTransaction;
    Widget*w;

private slots:
    void on_pushButton_clicked();

    void on_textEdit_textChanged();

private:
    Ui::transaction *ui;

    QString stockname;
    int number;//数量
    double price;
};

#endif // TRANSACTION_H
