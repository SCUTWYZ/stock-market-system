#pragma once
//�����Ʊ����
#ifndef STOCK_H
#define STOCK_H
#include<string>
#include<vector>
#include"stockholder.h"
#include"stockbase.h"
#include"plate.h"
#include"business.h"
#include"stockPerDay.h"
#include"commissionBusiness.h"
#include"totalclass.h"
#include"company.h"
#include"transaction.h"
using namespace std;


class stock :public stockbase{//���������Ҫ���࣬����һ֧�г�����ͨ�Ĺ�Ʊ��������Ϣ���Լ����ж����Ĳ���
	friend class mystock;
	friend class stockholder;
    friend class commissionBusiness;
    friend class MainWindow;
    friend class pbmore;
    friend class afterLoginin;
    friend class SubscriptionOfNewShares;
    friend class transaction;
    friend class God;
public:
    stock(company*);

    void modifystockmessage(double newPrice);//��Ʊ�۸�䶯�󣬸ı���һϵ�е��������

    void switchtoTrade();//ת��Ϊ�ɽ���

    virtual void beginTrade()=0;//��дʵ�ֶ�̬���̳�mainPlateStock,innovationPlateStock,��������ڿ��̵�ʱ����ã����¿��̼ۺ��ǵ�����Ϣ�����������ǵ�����ͬ

    void endTrade();//�������ף����У�����¼����Ĺ�Ʊ��Ϣ��stockPerDay��

    bool cantrade();//�����Ƿ�ɽ��׵�ֵ
	
	
    //����������ĵĴ����㷨 ��������������������������������1���ɽ���
	//��һ�� ����һ�������ȷ����������������е�ί�е���
	//�ڶ��� ��ʾ ��ӡ �̿���Ϣ
    //������  ��ɽ��ף����� ֻҪ���µ�ί�е����������ˢ�²����͵���һ��������� ���߹�����͵���һ�Σ�
	//���Ĳ� �жϽ��׳ɹ��� �����µ�business������ӵ�vector ���¹ɼۺ�����һϵ����Ϣ ����stockholder����Ϣ
	/*ϸ�ֲ��裺
	* 1 ĳһ�̵�����ί����Ϣ�ֳ����࣬���ȶԼ۸�����ͬһ�۸��ʱ�����򣨼۸�ֱ�����ͽ��򣩣�
	  2.ѡ��ǰ����۸�ͳ����Ӧ����������ӡ���̿�
	* 3..���򷽵�ί�ж���ִ���㷨�������ο���۸񣬶Ե�һ�������͵�һ���򵥣���۸�<=�򵥣���ɽ���ʽ��ף���������Ϊ��Ӧ����������С�ģ����ɵ���ʴ���һ��business������ʾ������
	* ��ÿ����һ��business����Ӧ���ĸ��ֹ�Ʊ�Ļ�����Ϣ�����Ļ�����Ϣ�ȵȣ�
	* 4..���ί����������ͬ�����޸ĳɽ���û��ȫ�ɽ�����������Ϣ��ί�й���Ϊһ���µ�ί�е���������ȫ�ɽ��Ĵ�vector��ȥ�����Ѻ���ĵ���ǰ�ƣ������µ�vector�������ӵڶ���ִ�У�ֱ��û�н���Ϊֹ
	* 5.����²�����һ��ί�е����͵���һ���������
	*/
    void strike();//���������ĵĹ�Ʊ�����㷨�������Ӵ�ÿ�γɹ����׺󣬻�Ҫ����stockholder��mystock��stock�����modify����ȥʵʩ�޸���Ϣ

    void showbuyPriceList();//�������̼�

    void showsellPriceList();//�������̼�

    void applytobuy(int applynumber,stockholder*applyholder);//����֧��Ʊ�¹��깺
	
	//�����㷨���




    static bool GreaterSort (commissionBusiness*a,commissionBusiness*b) ;//���������ڶԹ�Ʊ������
    static bool LessSort (commissionBusiness*a,commissionBusiness*b) ;

	
protected:
    //�����깺
    bool canTrade;//���깺�꣬������ͨ
    int tobeBuy;//ʣ��δ�������



	//��Ʊ���ƺʹ���͵�ǰ�۸񱻼̳�
	int totalStockNumber;//�ܹ���
	double initialPrice;//��ʼ�ɼ�
	 //�����ǹ�Ʊ�������Ϣ�������

	double currentTotalPrice;//��ͨ����ֵ�������ڹ�˾��ֵ�����ǡ����������ǹ�˾��ֵ�Ǿ��ʲ�*����������ǹɼ�*��������˾��ֵ��
	double raisingPrice;//��ֵ                 ��Ʊ�Ľ���û�й�ϵ����ȡ���ڹ�˾�����󣬵�����ͨ��ֵȡ���ڹ�Ʊ�Ľ��׼۸񣬼������
	double raisingRate;//�Ƿ�                   ��ֵ��������Ի�����ǰѧ���ļ�ֵ���ɣ��۸�Χ�Ƽ�ֵ�������ܹ����ϵӰ�죬��˾��ֵ
	//��Щ�ǻ��ڵ�ǰ�ɼ۶��仯��               �͡�finance.h��ľ��ʲ��������Կ������ڼ۸�
	
	double priceEnd;//���̼�
	double priceBegin;//���̼�
	double highest;//�������
	double lowest;//�������
	double limitUp;//��ͣ�ߣ����ǽ��տ��̼�*110%��120%��
	double limitDown;//��ͣ�ߣ����տ��̼�*80%��90%��
	int totalHandToday;//�����ܽ����֣�����������/100)
	//��Щ���Ƕ�����ֻ��Ʊÿһ������ݣ��ܵ�ǰ�ɼ�һ����Ӱ�죬������ʾ�ľ����ڱ�����ʾ��
	
    double totalRaisingRate;//���Ƿ�
	double historicalHighest;//��ʷ���
	double historicalLowest;//��ʷ���
	
	double realValue;// ÿ�ɾ��ʲ�
	double ROE;//���ʲ������ʣ���˾����/���ʲ���
	double PB;//�о��� ����ǰ�ɼ�/ÿ�ɾ��ʲ���
	double EPS;//ÿ������
	double PER;//��ӯ�� ����Ʊ��ǰ�۸�/ÿ�����棩
    company *thisCompany;
	//��Щ�͹�˾������Ϣ�йأ���Щ���ǹ�˾������Ϣ���ֵ��copy����
	
    //plate plate1;//��ҵ���
    //plate stockType;//������+���

	//������Ϣ���̿���Ϣ�ȵ�
    QVector<stockPerDay*>dayMessage;//ÿ�����Ϣ
    QVector<business*>businessMessage;//����ʱ�ɽ���ͼҪ�õ���������ݣ���ĳ����Ʊ�ѳɽ�����Ϣ����ʾ�ڡ��ֵ��ɽ�����
    //vector<commissionBusiness*>comMessage;//��Ʊί�е���Ϣ����Щ����ƽ����㷨��Ҫ�õ���
    QVector<commissionBusiness*>comofBuy;
    QVector<commissionBusiness*>comofSell;

    QVector<commissionBusiness*>BuyPriceList;
    QVector<commissionBusiness*>SellPriceList;
	//���ں��棨ֱ����	qt ��ӣ�����Ҫ�ټ�һϵ�е�chart ����Ϊstock�����ɣ�Ϊ������ʱͼ�󣬿��ܻ�Ҫ���һ����stockPerSecond"����������������Ϊ��λ�Ĺ�Ʊ��Ϣ�ࣩҲ���ܲ���
	
};

#endif



#pragma once
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
#endif // !INNOVATIONPLATESTOCK_H


#pragma once
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
#endif // !MAINPLATESTOCK_H


