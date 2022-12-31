#include "transaction.h"
#include "ui_transaction.h"

transaction::transaction(Widget*W,stockholder *_stockholderInTransaction,QWidget *parent) :
    QMainWindow(parent),
   stockholderInTransaction(_stockholderInTransaction) ,
   w(W),
 ui(new Ui::transaction)

{
    ui->setupUi(this);
}

transaction::~transaction()
{
    delete ui;
    w=nullptr;
    stockholderInTransaction=nullptr;
}

void transaction::on_pushButton_clicked()//交易按钮
{
    stockname=ui->textEdit->toPlainText();
    number=ui->textEdit_2->toPlainText().toInt();
    price=ui->textEdit_3->toPlainText().toDouble();
    int type=ui->comboBox->currentIndex();
     if(w->istrading==1)
     {

     for(int i=0;i<w->allstockvec.size();i++)
     {
     if(stockname==w->allstockvec[i]->stockName&&number%100==0&&w->allstockvec[i]->cantrade())
       {
         if(type==0&&number*price<=stockholderInTransaction->availableMoney)


         {stockholderInTransaction->buyStock(w->allstockvec[i],price,number);
             //交易后修改持有者的信息


             //
         this->close();
         }

         if(type==1)//卖单
         {for(int i=0;i<stockholderInTransaction->holderStock.size();i++)
                { if(stockholderInTransaction->holderStock[i]->stockName==stockname)
                   {if(stockholderInTransaction->holderStock[i]->positionNumber>=number)
                        {if(price<stockholderInTransaction->holderStock[i]->originStock->limitUp&&price>stockholderInTransaction->holderStock[i]->originStock->limitDown)
                     {stockholderInTransaction->sellStock(stockholderInTransaction->holderStock[i]->originStock,price,number);
                      this->close();
                     }

                        }
                   }
                }
         }//结束买单

       }
    }

  }
}
//交易按钮的执行代码结束
void transaction::on_textEdit_textChanged()
{

}
