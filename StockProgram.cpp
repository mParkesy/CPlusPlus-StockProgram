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
#include "Inventory.h"
using namespace std;

/**
 * 
 * @param items
 * @return 
 */

string removeCharacters(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' || str[i] == '\r') {
            str.erase(i, 1);
        }
    }
    return str;
}

Inventory getStockList(string file, Inventory inventory) {
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
            inventory.addStock(resistor);
        } else if (type == "transistor") {
            string tranType = removeCharacters(line.at(4));
            Transistor *transistor = new Transistor(tranType, type, code, stoi(quantity), stoi(price));
            inventory.addStock(transistor);
        } else if (type == "capacitor") {
            string capacitance = removeCharacters(line.at(4));
            Capacitor *capacitor = new Capacitor(capacitance, type, code, stoi(quantity), stoi(price));
            inventory.addStock(capacitor);
        } else if (type == "diode") {
            Diode *diode = new Diode(type, code, stoi(quantity), stoi(price));
            inventory.addStock(diode);
        } else if (type == "IC") {
            string ICtype = removeCharacters(line.at(4));
            IC *ic = new IC(ICtype, type, code, stoi(quantity), stoi(price));
            inventory.addStock(ic);
        }
    }
    return inventory;
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

    Inventory *inventory = new Inventory;

    cout << "File to be read: " << file << endl;
    cout << "Reading " << file << "..." << endl;
    inventory = getStockList(file, inventory);
    
    vector<StockItem*> items = getStockList(file);
    cout << "Stock Items successfully saved." << endl;

    cout << "" << endl;

    cout << "There are now " << inventory.getSize() << " Stock Items in the inventory." << endl;

    cout << "" << endl;

    // Print a list of the inventory, sorted in order of increasing price
    
    // What is the component with the largest number of components in stock?

    // How many NPN transistors does Chartlins have in stock?
    cout << "The number of NPN transistors that we have in stock is: " << inventory.getNumberOfNPN() << endl;


    // What is the total resistance of all of the resistors in stock?
    cout << "The total resistance of all resistors in stock is: ";
    cout << setprecision(12) << inventory.getAllResistance() << endl;


    // How man stock items have unit prices above 10p?

    cout << "The total number of items that are priced above 10 pence is: ";
    cout << inventory.getTotalStockAboveTen() << endl;

    return 0;

}




