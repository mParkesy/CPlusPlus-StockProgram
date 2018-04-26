/* 
 * File:   Inventory.cpp
 * Author: Parkesy
 * 
 * Created on 26 April 2018, 11:05
 */

#include "Inventory.h"

using namespace std;

Inventory::Inventory() {
}

Inventory::Inventory(const Inventory& orig) {
}

Inventory::~Inventory() {
    for(StockItem *item : this->inventory){
        delete item;
    }
}





