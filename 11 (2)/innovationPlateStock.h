/*#pragma once
#ifndef INNOVATIONPLATESTOCK_H
#define INNOVATIONPLATESTOCK_H


//��ҵ���
#include"stock.h"
class innovationPlateStock :public stock {
  public:

    innovationPlateStock(company*);
    void beginTrade() override;
//�ǵ���20%���趨��������Ա��ʱ��ͬ��������һ����Ȼ���ڹ�˾ע����������������һ������Ʊ����������1��ͷ����ҵ��0��ͷ�����˶��ѣ����˶���
};
#endif // !INNOVATIONPLATESTOCK_H*///���ͷ�ļ�д��stock.h����
