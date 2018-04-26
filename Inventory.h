/* 
 * File:   Inventory.h
 * Author: Parkesy
 *
 * Created on 26 April 2018, 11:05
 */

#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include "StockItem.h"

class Inventory {
private:
    std::vector<StockItem*> inventory;
    
public:
    Inventory();
    Inventory(const Inventory& orig);
    ~Inventory();
    inline int getSize() const;
    inline void addStock(StockItem *item);
    inline StockItem& getStock(int pos) const;
    inline void removeStock(int pos);
    StockItem& largestInStockComponent();
    int getNumberOfNPNTransistors();
    double getTotalInStockResistance();
    int getTotalStockAboveTenPence(int amount);
};

inline int Inventory::getSize() const {
    return inventory.size();
}

inline void Inventory::addStock(StockItem *item){
    inventory.push_back(item);
}

inline StockItem& Inventory::getStock(int pos) const 
{
    return *inventory.at(pos);
}

inline void Inventory::removeStock(int pos){
    inventory.erase(inventory.begin() + pos);
}

std::istream &operator>> (std::istream &is, Inventory &inv);

std::string removeCharacters(std::string str);

#endif /* INVENTORY_H */

