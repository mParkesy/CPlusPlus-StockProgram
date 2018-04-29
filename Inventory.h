/* 
 * File:        Inventory.h
 * Author:      100116544
 * Description: Header file for Inventory class which consists
 *              of StockItem objects.
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
    /**
     * Default constructor that creates a new Inventory object
     */
    Inventory();
    
    
    Inventory(const Inventory& orig);
    
    ~Inventory();

    /**
     * Returns how many StockItems have been added to the inventory
     * @return int - size of inventory
     */
    inline int getSize() const;
    
    /**
     * Adds a StockItem to the inventory
     * @param item - Pointer to a StockItem object to be added
     */
    inline void addStock(StockItem *item);
    
    /**
     * Gets a specific StockItem from a specific position in the inventory
     * @param pos - The position of the StockItem in the inventory
     * @return The StockItem thats been found
     */
    inline StockItem& getStock(int pos) const;
    
    /**
     * Deletes a specific StockItem from a specific position in the inventory 
     * @param pos - The position of the StockItem in the inventory
     */
    inline void removeStock(int pos);
    
    /**
     * Gets the current file that is set that will be read into the inventory
     * @return A string containing the file name
     */
    inline std::string getFile() const;
    
    /**
     * Sets the file that will be read into the inventory
     * @param file - The file name as a string 
     */
    inline void setFile(std::string file);
    
    /**
     * Gets the StockItem with the largest amount of stock from the inventory
     * @return The StockItem object
     */
    StockItem& largestInStockComponent();
    
    /**
     * Gets the total stock of all transistor of type NPN in the inventory
     * @return The amount of stock as an integer
     */
    int getNumberOfNPNTransistors();
    
    /**
     * Gets the total resistance of all in stock resistors in the inventory
     * @return The total resistance as a double
     */
    double getTotalInStockResistance();
    
    /**
     * Gets the total number of StockItems that are above a set 
     * price in the inventory
     * @param amount - The amount to be check against StockItem price
     * @return The number of StockItems above the price as an integer
     */
    int getTotalStockAbovePrice(int amount);
    
    /**
     * Sort the StockItems vector in the inventory by a specific type
     * @param sortType - The type of sort to be carried out as an integer
     */
    void sortInv(int sortType);
    
    /**
     * Grants separate function or class access to private 
     * members of the current class
     */
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

/**
 * Overload the << output stream operator so that an Inventory can
 * be printed in a suitable format
 * @param os - Reference to the output stream 
 * @param inv - Reference to the Inventory object which is to be printed
 * @return A reference to the output stream containing the Inventory object 
 */
std::ostream& operator<<(std::ostream &os, const Inventory &inv);

/**
 * Overload the >> input stream operator so that a Inventory can be read
 * @param is - Reference to the input stream
 * @param inv - Reference to the Inventory that reads the inventory  object in
 * @return A reference to the input stream that reads the Inventory object in 
 */
std::istream& operator>>(std::istream &is, Inventory &inv);

/**
 * Removes spaces and carriage returns on a given string
 * @param str - The string which will have spaces and CRs removed
 * @return The new string
 */
std::string removeCharacters(std::string str);

#endif /* INVENTORY_H */

