#include "widget.h"
#include "ui_widget.h"
#include"totalclass.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)

{    istrading=0;
    ui->setupUi(this);
    ui->label_6->setPixmap(QPixmap(":/QTpicture/xiaohui.jpg"));
     ui->tabWidget->setCurrentIndex(0);


      //显示所有现有账户
     finance *finance0=new finance(2021,6,1000000,100000,10);
      finance*finance1=new finance(2021,6,10000,1000,1);
       finance*finance2=new finance(2021,6,300000000,10000000,100);
        finance*finance3=new finance(2021,6,500000,2000000,30);
         finance*finance4=new finance(2021,6,1000000,1000000,5);
          finance*finance5=new finance(2021,6,30000000000,3000000,2000);
           finance*finance6=new finance(2021,6,800000,100000,50);

     allholdervec.push_back(new stockholder("韭菜",200000,"李却非","傻逼"));
     allholdervec.push_back(new stockholder("韭菜",200000,"王育之","天才"));
     allholdervec.push_back(new stockholder("机构",1000000,"rich","rich"));
      allholdervec.push_back((new stockholder("我是巴菲特",99999999999999,"巴菲特","")));
       allholdervec.push_back(new stockholder("地狱人机",999999999999999,"人机",""));
        allholdervec.push_back(new stockholder("机构",999999999999999,"华南理工大学","SCUT"));


     allcompanyvec.push_back(new company("育之股份","天才","育之股份",finance0));
      allcompanyvec.push_back(new company("却非科技","傻逼","却非科技",finance1));
        allcompanyvec.push_back(new company("华工酒业","SCUT","华工白酒",finance2));
         allcompanyvec.push_back(new company("华工银行","SCUT","华工银行",finance3));
          allcompanyvec.push_back(new company("忻傲集团","老公","忻傲集团",finance4));
           allcompanyvec.push_back(new company("贵州茅台","神股","贵州茅台",finance5));
            allcompanyvec.push_back(new company("华工电子","SCUT","华工电子",finance6));



     allstockvec.push_back(new mainPlateStock(allcompanyvec[0]));
      allstockvec.push_back(new innovationPlateStock(allcompanyvec[1]));
       allstockvec.push_back(new innovationPlateStock(allcompanyvec[2]));
        allstockvec.push_back(new mainPlateStock(allcompanyvec[3]));
         allstockvec.push_back(new innovationPlateStock(allcompanyvec[4]));
          allstockvec.push_back(new mainPlateStock(allcompanyvec[5]));
          allstockvec.push_back(new innovationPlateStock(allcompanyvec[6]));


     //这里用文件对三个vector初始化

}

Widget::~Widget()
{
    delete ui;
    //company1=nullptr;
    //company2=nullptr;
    allstockvec.clear();
    allholdervec.clear();
    allcompanyvec.clear();


}

//点击注册股东，跳转界面:
void Widget::on_pushButton_8_clicked()
{
    this->close();
    sign1*s1=new sign1(this);
    s1->show();

}
//点击注册公司，跳转界面:
void Widget::on_pushButton_9_clicked()
{
    this->close();
    sign2*s2=new sign2(this);
    s2->show();
}
//点击退出后，关闭界面
void Widget::on_pushButton_4_clicked()
{
    this->close();
}

void Widget::on_pushButton_2_clicked()
{
    this->close();
}

void Widget::on_pushButton_6_clicked()
{
    this->close();
}

void Widget::on_pushButton_clicked()//登录股东账户界面
{
    QString getuserName=ui->lineEdit_2->text();
    QString getpassword=ui->lineEdit->text();



   for(int i=0;i<allholdervec.size();i++)
        if(getuserName==allholdervec[i]->userName&&getpassword==allholdervec[i]->password)
        {
            this->close();
            afterLoginin*al=new afterLoginin (this,allholdervec[i]);
            al->show();
        }

}

void Widget::on_pushButton_5_clicked()//登录上帝
{
    God*god1=new God(this);
    god1->show();
}

void Widget::on_pushButton_3_clicked()//公司登录
{
    QString getuserName=ui->lineEdit_6->text();
    QString getpassword=ui->lineEdit_5->text();



   for(int i=0;i<allcompanyvec.size();i++)
        if(getuserName==allcompanyvec[i]->userName&&getpassword==allcompanyvec[i]->password)
        {

            ListedCompany *list=new ListedCompany (this,allcompanyvec[i]);
            list->show();
            this->close();

        }
}
