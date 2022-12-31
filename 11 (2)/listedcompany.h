#ifndef LISTEDCOMPANY_H
#define LISTEDCOMPANY_H

#include <QMainWindow>
#include"stockholder.h"
namespace Ui {
class ListedCompany;
}

class ListedCompany : public QMainWindow//以公司的身份登录后，查看与修改信息的界面
{
    Q_OBJECT

public:
    explicit ListedCompany(Widget*,company*,QWidget *parent = nullptr);
    ~ListedCompany();
    Widget*w;
    company*thiscompany;

private slots:
    void on_pushButton_clicked();

private:
    Ui::ListedCompany *ui;
};

#endif // LISTEDCOMPANY_H
