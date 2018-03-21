#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include"StockItem.cpp"
using namespace std;

int main()
{

	vector<StockItem> items;
	ifstream infile("inventory.txt");

	while (infile) {
		string s;
		if (!getline(infile, s)) {
			break;
		}

		istringstream ss(s);
		vector<string> line;
		while (ss) {

			string s;
			if (!getline(ss, s, ',')) {
				break;
			}
			line.push_back(s);
		}
		if (line.size() == 5) {
			StockItem item(line.at(0), line.at(1), stoi(line.at(2)), stoi(line.at(3)), line.at(4));
			items.push_back(item);
		}
		else {
			StockItem item(line.at(0), line.at(1), stoi(line.at(2)), stoi(line.at(3)));
			items.push_back(item);
		}
		
	}

	if (!infile.eof()) {
		cout << "Done\n";
	}

	for (int i = 0; i < items.size(); i++) {
		cout << items.at(i).getCode() << endl;
	}

	return 0;
}

