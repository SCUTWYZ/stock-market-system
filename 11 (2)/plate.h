#pragma once
#ifndef PLATE_H
#define PLATE_H


//��鶨��
#include"stock.h"
#include<vector>
#include"totalclass.h"
class plate {
public:plate();
    ~plate();

private:
	vector<stock>plateStock;//һ����������ɹ�Ʊ��ɣ���ӳĳЩ�ض���Ʊ������Ƿ�����
	double raisingRate;//������������ǵ���

};
#endif // !PLATE_H
