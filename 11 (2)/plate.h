#pragma once
#ifndef PLATE_H
#define PLATE_H


//板块定义
#include"stock.h"
#include<vector>
#include"totalclass.h"
class plate {
public:plate();
    ~plate();

private:
	vector<stock>plateStock;//一个板块由若干股票组成，反映某些特定股票总体的涨幅跌幅
	double raisingRate;//这个板块总体的涨跌幅

};
#endif // !PLATE_H
