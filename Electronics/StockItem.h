#include <string>
using namespace std;

#ifndef StockItem_H
#define StockItem_H

class StockItem {
private:
	string itemType;
	string stockCode;
	int stock;
	int price;
	string additional;

public:
	StockItem(string type, string code, int number, int pence, string add);
	~StockItem();
	string getType();
	string getCode();
	int getStock();
	int getPrice();
	string getAdditional();
};

#endif