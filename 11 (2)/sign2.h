#ifndef SIGN2_H
#define SIGN2_H

#include <QWidget>
#include<widget.h>
#include"stockholder.h"
namespace Ui {
class sign2;
}

class sign2 : public QWidget//公司注册界面
{
    Q_OBJECT

public:
    explicit sign2(Widget*,QWidget *parent = nullptr);
    ~sign2();

    stockholder*stockholderInSign2;
    Widget*w;
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::sign2 *ui;
};

#endif // SIGN2_H
