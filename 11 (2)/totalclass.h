#ifndef TOTALCLASS_H
#define TOTALCLASS_H
class finance;
class Widget;
class business;
class commissionBusiness;
class company;
class mystock;
class plate;
class stock;
class stockholder;
class stockPerDay;
class sign1;

class totalclass{//在这里先声明好类，在必要的文件包含，修复未定义，类不完整的bug
    friend class sign1;
    friend class Widget;
public:
    totalclass();
    //static stockholder* holderele;
};

#endif // TOTALCLASS_H
