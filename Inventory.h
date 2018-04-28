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
    std::string currentFile;
public:
    Inventory();
    Inventory(const Inventory& orig);
    ~Inventory();
    inline int getSize() const;
    inline void addStock(StockItem *item);
    inline StockItem& getStock(int pos) const;
    inline void removeStock(int pos);
    inline std::string getFile() const;
    inline void setFile(std::string file);
    StockItem& largestInStockComponent();
    int getNumberOfNPNTransistors();
    double getTotalInStockResistance();
    int getTotalStockAboveTenPence(int amount);
    void sortInv(int sortType);
    friend std::ostream& operator<<(std::ostream &os, const Inventory &inv);
    
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

inline std::string Inventory::getFile() const {
    return this->currentFile;
}

inline void Inventory::setFile(std::string file) {
    this->currentFile = file;
}

std::ostream& operator<<(std::ostream &os, const Inventory &inv);
std::istream& operator>>(std::istream &is, Inventory &inv);

std::string removeCharacters(std::string str);

#endif /* INVENTORY_H */

