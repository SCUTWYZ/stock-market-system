#pragma once
#ifndef STOCKBASE_H
#define STOCKBASE_H
#include"QString"


//��Ʊ���࣬�����������Ϣ
#include<string>
using namespace std;
class stockbase {//��Ʊ���࣬������Ʊ����������Ϣ
    friend class MainWindow;
    friend class Finance;
    friend class transactionInformation;
public:
    stockbase(QString,QString,double);

    QString stockName;//��Ʊ��
    QString stockCode;//��Ʊ����
	double currentPrice;//��Ʊ��ǰ�۸�

};
#endif
