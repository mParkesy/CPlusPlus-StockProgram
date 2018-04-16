#include <string>
using namespace std;

#ifndef StockItem_H
#define StockItem_H

//class StockItem {
//	enum class type {resistor, capacitor, diode, transistor, IC};
//	string stockCode;
//	int stock;
//	int price;
//};

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

class Resistor : public StockItem {
private:
	string resistance;

public:
	Resistor(string resistance);
};

class capacitor : public StockItem {
private:
	double capitance;
};

class diode : public StockItem {

};

class transistor : public StockItem {
private:
	string tranType;
};

#endif