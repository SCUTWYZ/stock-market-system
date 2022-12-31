#include "sign1.h"
#include "ui_sign1.h"
#include"stockholder.h"
#include"totalaccount.h"
#include<QFile>
#include <QFileDialog>
#include<QFileInfo>
#include<QByteArray>
sign1::sign1(Widget*_w,QWidget *parent) :
    QWidget(parent),
    w(_w),
    ui(new Ui::sign1)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

}

sign1::~sign1()
{
    delete ui;
}

void sign1::on_pushButton_4_clicked()
{
  //确认按钮返回主界面
    this->close();
  w->show();
}

void sign1::on_pushButton_6_clicked()
{//确认按钮返回主界面
    this->close();
   w->show();
}

//股民注册
void sign1::on_pushButton_3_clicked(){

    QString account= ui->lineEdit->text();
        QString password = ui->lineEdit_2->text();
         double pinitialmoney;
         if(this->ui->radioButton_5->isChecked())
             pinitialmoney=100000000;
         if(this->ui->radioButton_6->isChecked())
              pinitialmoney=2000000000;
         if(this->ui->radioButton_7->isChecked())
              pinitialmoney=5000000000;
         if(this->ui->radioButton_8->isChecked())
             pinitialmoney=10000000000;
         //文件写入

                         //写入账户
                        QString path ="C:\\Users\\32715\\Desktop\\account.txt"; //QFileDialog::getExistingDirectory(this,"","C:\\Users\\32715\\Desktop\\password.txt");
                        QFile file (path);

                         file.open(QIODevice::WriteOnly);
                          file.write(account.toLatin1().data());
                            file.close();

                             //写入密码
                             QString path1 ="C:\\Users\\32715\\Desktop\\password.txt"; //QFileDialog::getExistingDirectory(this,"","C:\\Users\\32715\\Desktop\\password.txt");
                             QFile file1 (path1);
                             file1.open(QIODevice::WriteOnly);
                               file1.write(password.toLatin1().data());

                               file1.close();



                                vec1.push_back(new stockholder("机构",pinitialmoney,account,password));
                                   this->close();
                                   w->show();

}
//机构注册
void sign1::on_pushButton_5_clicked()
{    QString account= ui->lineEdit_3->text();
     QString password = ui->lineEdit_4->text();
      double pinitialmoney;
      if(this->ui->radioButton_2->isChecked())
          pinitialmoney=100000000;
      if(this->ui->radioButton->isChecked())
           pinitialmoney=2000000000;
      if(this->ui->radioButton_3->isChecked())
           pinitialmoney=5000000000;
      if(this->ui->radioButton_4->isChecked())
          pinitialmoney=10000000000;


      QString path ="C:\\Users\\32715\\Desktop\\account.txt";
      QFile file (path);

       file.open(QIODevice::Append);
        file.write(account.toLatin1().data());


         file.seek(file .pos()+1);

          file.write(password.toLatin1().data());
           file.seek(file .pos()+1);
            //file.write(QString::number(pinitialmoney).toLatin1().data());
            file.seek(file .pos()+1);
          file.close();
           QFile file2(path);
            file.open(QIODevice::ReadOnly);

           //qDebug()<<file.readLine();

this->close();
w->show();

}
