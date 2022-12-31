#ifndef GOD_H
#define GOD_H

#include <QMainWindow>
#include"stockholder.h"
namespace Ui {
class God;
}

class God : public QMainWindow//控制是否开盘的界面
{
    Q_OBJECT

public:
    explicit God(Widget* ,QWidget *parent = nullptr);
    ~God();
    Widget *w;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::God *ui;
};

#endif // GOD_H
