/* 
 * File:   Inventory.cpp
 * Author: Parkesy
 * 
 * Created on 26 April 2018, 11:05
 */

using namespace std;

#include "Inventory.h"
#include "StockItem.h"

Inventory::Inventory() {
}

Inventory::Inventory(const Inventory& orig) {
}

Inventory::~Inventory() {
    for (StockItem *item : inventory) {
        delete item;
    }
}

StockItem& Inventory::largestInStockComponent() {
    StockItem *largest;
    largest->setStock(0);
    for(StockItem *stockitem : inventory) {
        if(stockitem->getStock() > largest->getStock()){
            largest->setStock(stockitem->getStock());
        }
    }
    return *largest;
}

int Inventory::getNumberOfNPNTransistors() {
    int total = 0;
    for (StockItem *stockitem : inventory) {
        if (stockitem->getInfo() == "NPN") {
            total++;
        }
    }
    return total;
}

double Inventory::getTotalInStockResistance() {
    double total = 0;
    for (StockItem *stockitem : inventory) {
        if (stockitem->getStock() > 0 && stockitem->getType() == "resistor") {
            total +=  stod(stockitem->getInfo()) * stockitem->getStock();
        }
    }
    return total;
}

int Inventory::getTotalStockAboveTenPence(int amount) {
    int stockTotal = 0;
    for (StockItem *stockitem : this->inventory) {
        if (stockitem->getPrice() > amount) {
            stockTotal++;
        }
    }
    return stockTotal;
}


