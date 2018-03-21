#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class StockItem {
	public:
		string itemType;
		string stockCode;
		int stock;
		int price;
		string additional;

		StockItem(string type, string code, int number, int pence, string add) {
			this -> itemType = type;
			this-> stockCode = code;
			this-> stock = number;
			this-> price = pence;
			this-> additional = add;
		}

		StockItem(string type, string code, int number, int pence) {
			this-> itemType = type;
			this-> stockCode = code;
			this-> stock = number;
			this-> price = pence;
			this-> additional = "";
		}

		~StockItem() {
			
		}
		
		string getType() {
			return itemType;
		}

		string getCode() {
			return this-> stockCode;
		}

		int getStock() {
			return stock;
		}

		int getPrice() {
			return price;
		}

		string getAdditional() {
			return additional;
		}



};