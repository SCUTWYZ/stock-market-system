#pragma once
#ifndef COMPANY_H
#define COMPANY_H


//��˾
#include"totalclass.h"
#include<QVector>
#include<QDateTime>//ע�����������������ͷ�ļ���ctime�����ʱ�䣬����qt��ת����QDateTime��
#include"finance.h"
#include<string>
#include"account.h"
#include"stock.h"
using namespace std;
class company :public account{//�Թ�˾��ݵ�¼�������Ϣ����������Ϊһ����Ʊ�ĳ�Ա�����������Ϣ
    friend class stock;
    friend class Finance;
    friend class ListedCompany;
public:
    company(QString name,QString word, QString,finance *firstfinance);
    void registerInf(int year,int month,double _profit);//��˾���Ĳ�����Ϣ������������

protected:
    QDateTime listTime;//����ʱ�䣬�ͼ�¼��˾�˻��ɹ�ע���ϵͳʱ�䣨��ζ�Ź�Ʊͨ��Ҫ�󣬿������У�
    QString stockname;
	//��˾��������̳�username
    stock* thisStock;//��˾��ע��Ĺ�Ʊ
    finance*myFinance;//��˾ÿ���²�����Ϣ


	
};
#endif // !COMPANY_H
