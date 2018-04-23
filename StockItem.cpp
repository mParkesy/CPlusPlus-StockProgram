/* 
 * File:   StockItem.cpp
 * Author: Parkesy
 * 
 * Created on 19 April 2018, 12:20
 */

#include "StockItem.h"
#include <iostream>

StockItem::StockItem() {

}

StockItem::StockItem(string type, string code, int number, int pence) {
    this -> itemType = std::move(type);
    this -> stockCode = std::move(code);
    this -> stock = number;
    this -> price = pence;
}

StockItem::~StockItem() {

}

string StockItem::getType() {
    return this -> itemType;
}

string StockItem::getCode() {
    return this -> stockCode;
}

int StockItem::getStock() {
    return this -> stock;
}

int StockItem::getPrice() {
    return this -> price;
}

Resistor::Resistor(string resistance, string type, string code, int number, int pence) : StockItem(type, code, number, pence) {
    this -> resistance = std::move(resistance);
}

string Resistor::getResistance(){
    return this -> resistance;
}

double Resistor::getNumericalResistance() {
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
    //cout << "Test: " << result  << endl;
    return stod(firstDigits) * multiplier;
}

Capacitor::Capacitor(string capacitance, string type, string code, int number, int pence) : StockItem(type, code, number, pence) {
    this -> capacitance = capacitance;
}

string Capacitor::getCapacitance(){
    return this -> capacitance;
}

Diode::Diode(string type, string code, int number, int pence) : StockItem(type, code, number, pence){
    
}

Transistor::Transistor(string transistorType, string type, string code, int number, int pence) : StockItem(type, code, number, pence){
    this -> transistorType = transistorType;
}

string Transistor::getTransistorType(){
    return this -> transistorType;
}

IC::IC(string ICtype, string type, string code, int number, int pence) : StockItem(type, code, number, pence){
    this -> ICtype = ICtype;
}

string IC::getICtype(){
    return this -> ICtype;
}