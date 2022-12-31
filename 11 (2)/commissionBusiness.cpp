#include"commissionBusiness.h"
#include"stock.h"
#include"stockholder.h"
commissionBusiness::commissionBusiness( stockholder *_thisHolder, bool _isbuy,stock* _thisStock, int _comNumber ,double _comPrice)
{
thisHolder=_thisHolder;
isbuy = _isbuy;
isComplete = 0;
thisStock = _thisStock;
comNumber = _comNumber;
comPrice = _comPrice;
comTime = QDateTime::currentDateTime();
}//在stockholder类里面的两个交易函数可以生成这样一个单子


void commissionBusiness::withdraw()
{

if(isComplete==0)
    {
     for(int i=0;i<thisHolder->holdercommission.size();i++)
        {
         if(this->comTime==thisHolder->holdercommission[i]->comTime)
           {
             thisHolder->holdercommission.remove(i);
             break;
           }
        }


         if (this->isbuy)
             for(int i=0;i<thisStock->comofBuy.size();i++)
                {
                 if(this->comTime==this->thisStock->comofBuy[i]->comTime)
                   {
                     thisStock->comofBuy.remove(i);
                     break;
                   }
                }

         else
             for(int i=0;i<thisStock->comofSell.size();i++)
         {
          if(this->comTime==this->thisStock->comofSell[i]->comTime)
            {
              thisStock->comofSell.remove(i);
              break;
            }
         }



    }
}//对这个单子，如果没成交可以撤单

