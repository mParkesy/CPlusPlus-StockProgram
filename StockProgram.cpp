/* 
 * File:   main.cpp
 * Author: Parkesy
 *
 * Created on 19 April 2018, 11:18
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "StockItem.h"
using namespace std;

/**
 * 
 * @param items
 * @return 
 */
vector<Resistor*> getResistorList(vector<StockItem*> items) {
    vector<Resistor*> list;
    for (StockItem *stockitem : items) {
        if (stockitem->getType() == "resistor") {
            Resistor *res = dynamic_cast<Resistor*> (stockitem);
            list.push_back(res);
        }
    }
    return list;
}

double getAllResistance(vector<Resistor*> resistors) {
    double total;
    for(Resistor *r : resistors){
        if(r->getStock() > 0){
            total += r->getNumericalResistance();
        }
    }
    return total;
}

int getTotalStockAboveTen(vector<StockItem*> items) {
    int stockTotal = 0;
    for (StockItem *stockitem : items) {
        if (stockitem->getPrice() > 10) {
            stockTotal++;
        }
    }
    return stockTotal;
}

int getNumberOfNPN(vector<StockItem*> items) {
    int total = 0;
    for (StockItem *stockitem : items) {
        if (stockitem->getType() == "transistor") {
            Transistor *tran = dynamic_cast<Transistor*> (stockitem);
            if (tran->getTransistorType() == "NPN") {
                total++;
            }
        }
    }
    return total;
}

string largestInStockComponent(vector<StockItem*> items){
    for(StockItem *stockitem : items){
        string type = stockitem->getType();
        if(type == "resistor"){

        } else if(type == "capacitor"){

        } else if(type == "diode"){

        } else if(type == "transistor"){

        } else if(type == "IC"){

        }
    }
    
}

//vector<StockItem*> sortPrice(vector<StockItem*> items){
//    sort(items.begin(), items.end(), 
//    (const StockItem * a, const StockItem b) -> bool
//    { 
//        return a->getPrice() < b->getPrice();
//    });
//    for(StockItem *stockitem : items){
//        cout << stockitem->getPrice() << endl;
//    }
//    return items;
//}

string removeCharacters(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' || str[i] == '\r') {
            str.erase(i, 1);
        }
    }
    return str;
}

vector<StockItem*> getStockList(string file) {
    vector<StockItem*> items;
    ifstream infile(file);
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
        string type = line.at(0);
        string code = line.at(1);
        string quantity = line.at(2);
        string price = line.at(3);

        if (type == "resistor") {
            string resistance = removeCharacters(line.at(4));
            Resistor *resistor = new Resistor(resistance, type, code, stoi(quantity), stoi(price));
            items.push_back(resistor);
        } else if (type == "transistor") {
            string tranType = removeCharacters(line.at(4));
            Transistor *transistor = new Transistor(tranType, type, code, stoi(quantity), stoi(price));
            items.push_back(transistor);
        } else if (type == "capacitor") {
            string capacitance = removeCharacters(line.at(4));
            Capacitor *capacitor = new Capacitor(capacitance, type, code, stoi(quantity), stoi(price));
            items.push_back(capacitor);
        } else if (type == "diode") {
            Diode *diode = new Diode(type, code, stoi(quantity), stoi(price));
            items.push_back(diode);
        } else if (type == "IC") {
            string ICtype = removeCharacters(line.at(4));
            IC *ic = new IC(ICtype, type, code, stoi(quantity), stoi(price));
            items.push_back(ic);
        }
    }
    return items;
}

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "========================================" << endl;
    cout << "              StockProgram              " << endl;
    cout << "========================================" << endl;
    
    cout << "" << endl;
    
    string file = "inventory.txt";
    
    cout << "File to be read: " << file << endl;
    cout << "Reading " << file << "..." << endl;
    vector<StockItem*> items = getStockList(file);
    cout << "Stock Items successfully saved." << endl;

    cout << "" << endl;
    
    cout << "There are " << items.size() << " Stock Items in " << file << endl;
     
    cout << "" << endl;
    
//    char decision;
//    cout << "Would you like to see the list of Inventory Items? (y or n): " <<;
//    cin >> decision;
//    
//    if(decision == 'y'){
//        for (StockItem *stockitem : items) {
//            cout << 
//        }
//    }
    

    // Print a list of the inventory, sorted in order of increasing price
    // What is the component with the largest number of components in stock?

    // How many NPN transistors does Chartlins have in stock?
    cout << "The number of NPN transistors that we have in stock is: " << getNumberOfNPN(items) << endl;
    
    
    // What is the total resistance of all of the resistors in stock?
    cout << "The total resistance of all resistors in stock is: ";
    vector<Resistor*> rList = getResistorList(items);
    cout << setprecision(12) << getAllResistance(rList) << endl;

    
    // How man stock items have unit prices above 10p?
    
    cout << "The total number of items that are priced above 10 pence is: ";
    cout << getTotalStockAboveTen(items) << endl;

    return 0;

}




