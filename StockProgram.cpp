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
#include"StockItem.h"
using namespace std;

vector<Resistor> getResistorList(vector<StockItem> items){
    vector<Resistor> list;
    for (int i = 0; i < items.size(); i++) {
        if(items[i].getType() == "resistor"){
            
        }
    }
}

double getAllResistance(vector<Resistor> resistors) {
    double total;
    for (int i = 0; i < resistors.size(); i++) {
        total += resistors.at(i).getNumericalResistance();
    }
    return total;
}
/*
 * 
 */
int main(int argc, char** argv) {
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
        if (line.at(0) == "resistor") {
            Resistor item(line.at(4), line.at(0), line.at(1), stoi(line.at(2)), stoi(line.at(3)));
            items.push_back(item);
        }
    }


    //for (int i = 0; i < resistors.size(); i++) {
    //    cout << resistors.at(i).getResistance() << endl;
    //}
    
    cout << setprecision(9) << getAllResistance(getResistorList(items)) << endl;
    
    return 0;
}



