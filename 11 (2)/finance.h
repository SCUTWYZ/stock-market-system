#pragma once
#ifndef FINANCE_H
#define FINANCE_H
#include"QDateTime"
#include"listedcompany.h"
//��˾ĳ���µĲ�����Ϣ����ЩΪʲôҪ��12�أ���Ϊ�������ǰ����㣬����ʵ����Щ���ʶ��ǰ��������㣩

class finance {   //����һ����˾�Ĳ�����Ϣ
   friend class company;
   friend class stock;
   friend class Finance;
   friend class ListedCompany;
public:
    finance(int year,int month,double _profit,double _stockNumber,double _stockinitialPrice);//ע�ṫ˾��ʱ���ʼ��������Ϣ
    void modify(int year,int month,double _profit);//���²�����Ϣ


protected:
	int registerYear;//��˾��β�����Ϣ����д��
	int registerMonth;//��˾��β�����Ϣ����д�� ��ע������¸���û����д����˳���ϸ��£�
	double profit;//����,����ÿ��ֻҪ����һ��
	double totalValue;// ��˾��ǰ����ֵ  ��������ֵ+����
	double stockNumber;//����
	double stockinitialPrice;//���йɼۣ�Ҳ���ǽ��������ÿ�ɽ�
	double realValue;// ÿ�ɾ��ʲ��� ���ڵ�ÿ�ɾ��ʲ�+����/�ܹ����������ÿ�ɾ��ʲ�Ϊ���йɼۣ�
	double ROE;//���ʲ������ʣ���˾����*12/������ÿ�ɾ��ʲ�*��������
	double EPS;//ÿ������   ��ÿ�ɾ��ʲ�-����ÿ�ɾ��ʲ���*12
	

};
#endif // !FINANCE_H
