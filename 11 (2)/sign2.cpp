#include "sign2.h"
#include "ui_sign2.h"

sign2::sign2(Widget*_w,QWidget *parent) :
    QWidget(parent),
    w(_w),
    ui(new Ui::sign2)
{
    ui->setupUi(this);
}

sign2::~sign2()
{
    delete ui;
}

void sign2::on_pushButton_4_clicked()
{
    //确认按钮返回主界面
    this->close();
    w->show();
}

void sign2::on_pushButton_3_clicked(){
    this->close();
    w->show();
}
