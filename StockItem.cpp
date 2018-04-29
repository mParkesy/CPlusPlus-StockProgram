/* 
 * File:   StockItem.cpp
 * Author: Parkesy
 * 
 * Created on 19 April 2018, 12:20
 */

#include "StockItem.h"

using namespace std;
// ===============================STOCKITEM====================================

StockItem::StockItem() {

}

StockItem::StockItem(string type, string code, int number, int pence) {
    type[0] = toupper(type[0]);
    this -> itemType = std::move(type);
    this -> stockCode = std::move(code);
    this -> stock = number;
    this -> price = pence;
}

StockItem::StockItem(const StockItem& orig){
    
}

StockItem::~StockItem() {
    
}

// ===============================RESISTOR=====================================

Resistor::Resistor(string resistance, string type, string code,
        int number, int pence) : StockItem(type, code, number, pence) {
    this -> resistance = std::move(resistance);
}

string Resistor::getInfo() {
    string firstDigits = "";
    string secondDigits = "";
    string letter = "";
    for (int i = 0; i < resistance.length(); i++) {
        if (isdigit(resistance[i]) && letter.length() == 0) {
            firstDigits = firstDigits + resistance[i];
            //cout << firstDigits;
        } else if (isalpha(resistance[i]) && letter.length() == 0) {
            letter = resistance[i];
            //cout << letter;
        } else if (isdigit(resistance[i]) && letter.length() > 0) {
            secondDigits = secondDigits + resistance[i];
            //cout << secondDigits;
        }
    }
    //cout << " Result: ";
    int multiplier;
    if (letter == "R") {
        multiplier = 1;
    } else if (letter == "K") {
        multiplier = 1000;
    } else if (letter == "M") {
        multiplier = 1000000;
    }
    if (secondDigits.length() > 0) {
        firstDigits = firstDigits + "." + secondDigits;
    }
    double result = stod(firstDigits) * multiplier;
    return to_string(result);
}

// ===============================CAPACITOR====================================

Capacitor::Capacitor(string capacitance, string type, string code,
        int number, int pence) : StockItem(type, code, number, pence) {
    this -> capacitance = capacitance;
}

string Capacitor::getInfo() {
    return this -> capacitance;
}

//string Capacitor::getInfo() {
//    string c = "";
//    string units = "";
//    for (int i = 0; i < capacitance.length(); i++) {
//        if (isdigit(capacitance[i])) {
//            c = c + capacitance[i];
//        } else if (isalpha(capacitance[i])) {
//            units = units + capacitance[i];
//        }
//    }
//    double multiplier = 0;
//    if (units == "pf") {
//        multiplier = 0.000001;
//    } else if (units == "nF" || units == "nf") {
//        multiplier = 1000;
//    } else if (units == "uF") {
//        multiplier = 0;
//    }
//    
//    double result = stod(c) * multiplier;
//    return to_string(result);
//}

// =================================DIODE======================================

Diode::Diode(string type, string code, int number, int pence)
: StockItem(type, code, number, pence) {
}

string Diode::getInfo() {
    return "n/a";
}

// ===============================TRANSISTOR===================================

Transistor::Transistor(string transistorType, string type, string code,
        int number, int pence) : StockItem(type, code, number, pence) {
    this -> transistorType = transistorType;
}

string Transistor::getInfo() {
    return this -> transistorType;
}

// ===================================IC=======================================

IC::IC(string ICtype, string type, string code, int number,
        int pence) : StockItem(type, code, number, pence) {
    this -> ICtype = ICtype;
}

string IC::getInfo() {
    return this -> ICtype;
}