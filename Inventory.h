/* 
 * File:   Inventory.h
 * Author: Parkesy
 *
 * Created on 26 April 2018, 11:05
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
private:
    std::list<StockItem*> inventory;
    
public:
    Inventory();
    Inventory(const Inventory& orig);
    virtual ~Inventory();
    inline int getSize() const;
    inline void addStock(StockItem *item);
    inline StockItem& getStock(int pos) const;
    inline void removeStock(int pos);
};

inline int Inventory::getSize() const {
    return inventory.size();
}

inline void Inventory::addStock(StockItem *item){
    inventory.push_back(item);
}

inline StockItem& Inventory::getStock(int pos) const 
{
    return *inventory[pos];
}

inline void Inventory::removeStock(int pos){
    inventory.remove(inventory.begin() + pos);
}

inline 
#endif /* INVENTORY_H */

