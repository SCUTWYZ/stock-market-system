/*#pragma once
#ifndef MAINPLATESTOCK_H
#define MAINPLATESTOCK_H

//�����Ʊ
#include"stock.h"
class mainPlateStock :public stock{
public:

    mainPlateStock(company*);

    void beginTrade() override;
	//����stock������֮һ��׼��������ͬ���ǵ�����ͬ������Ϊ10%
};
#endif // !MAINPLATESTOCK_H*///���ͷ�ļ�д��stock.h����
