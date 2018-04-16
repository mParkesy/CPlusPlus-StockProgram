#include "stdafx.h"
#include "StockItem.h"

StockItem::StockItem(string type, string code, int number, int pence, string add) {
	this -> itemType = type;
	this-> stockCode = code;
	this-> stock = number;
	this-> price = pence;
	this-> additional = add;
}


StockItem::~StockItem() {
			
}
		
string StockItem::getType() {
	return this-> itemType;
}

string StockItem::getCode() {
	return this-> stockCode;
}

int StockItem::getStock() {
	return this-> stock;
}

int StockItem::getPrice() {
	return this-> price;
}

string StockItem::getAdditional() {
	return this-> additional;
}


Resistor::Resistor(string resistance) : StockItem(string type, string code, int number, int pence, string add){


}
