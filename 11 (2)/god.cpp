#include "god.h"
#include "ui_god.h"

God::God(Widget*_w,QWidget *parent) :
    QMainWindow(parent),
    w(_w),
    ui(new Ui::God)
{
    ui->setupUi(this);
    ui->label->setText(w->istrading==true?"交易中":"休市中");
}

God::~God()
{
    delete ui;
}

void God::on_pushButton_2_clicked()//改变
{
    w->istrading=(w->istrading==true?false:true);
    ui->label->setText(w->istrading==true?"交易中":"休市中");
    ui->pushButton_2->setText(w->istrading==true?"停盘":"开盘");
    if(w->istrading==1)
       {for(int i=0;i<w->allstockvec.size();i++)
        {if(w->allstockvec[i]->tobeBuy==0)
            {w->allstockvec[i]->beginTrade();}}}

    else {for(int i=0;i<w->allstockvec.size();i++)
        {if(w->allstockvec[i]->tobeBuy==0)
            {w->allstockvec[i]->endTrade();}}

    }

}

void God::on_pushButton_clicked()//退出，这里要给文件存档信息
{
      this->close();
      w->show();
}
