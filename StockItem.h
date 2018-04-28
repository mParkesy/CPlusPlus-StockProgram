/* 
 * File:   StockItem.h
 * Author: Parkesy
 *
 * Created on 19 April 2018, 12:20
 */

#ifndef StockItem_H
#define StockItem_H
#include <string>
#include <iomanip>
#include <iostream>

// ===============================STOCKITEM====================================

class StockItem {
private:
    std::string itemType;
    std::string stockCode;
    int stock;
    int price;

public:
    StockItem();
    StockItem(std::string type, std::string code, int number, int pence);
    ~StockItem();
    inline std::string getType() const;
    inline std::string getCode() const;
    inline int getStock() const;
    inline int getPrice() const;
    virtual std::string getInfo() = 0;
    inline void setType(std::string type);
    inline void setCode(std::string code);
    inline void setStock(int stock);
    friend std::ostream& operator<<(std::ostream &os, const StockItem &item);
};

inline std::string StockItem::getType() const {
    return this -> itemType;
}

inline std::string StockItem::getCode() const {
    return this -> stockCode;
}

inline int StockItem::getStock() const {
    return this -> stock;
}

inline int StockItem::getPrice() const {
    return this -> price;
}

inline void StockItem::setType(std::string type) {
    this->itemType = type;
}

inline void StockItem::setCode(std::string code) {
    this->stockCode = code;
}

inline void StockItem::setStock(int stock) {
    this->stock = stock;
}

inline std::ostream& operator<<(std::ostream &os, const StockItem &item)
{
   return os << "Type: " << item.itemType << "\n"
             << "Code: " << item.stockCode << "\n"
             << "Stock: " << item.stock << "\n"
             << "Price: " << item.price <<  "\n"
           << "Info: " << item.getInfo() << std::endl;
}

std::istream& operator>>(std::istream &is, StockItem &item);

// ===============================RESISTOR=====================================

class Resistor : public StockItem {
private:
    std::string resistance;
public:
    Resistor(std::string resistance, std::string type, std::string code,
            int number, int pence);
    std::string getInfo();
};


// ===============================CAPACITOR====================================

class Capacitor : public StockItem {
private:
    std::string capacitance;
public:
    Capacitor(std::string capacitance, std::string type, std::string code,
            int number, int pence);
    std::string getInfo();
};

// ==================================DIODE=====================================

class Diode : public StockItem {
public:
    Diode(std::string type, std::string code, int number, int pence);
    std::string getInfo();
};

// ===============================TRANSISTOR===================================

class Transistor : public StockItem {
private:
    std::string transistorType;
public:
    Transistor(std::string transistorType, std::string type, std::string code, int number, int pence);
    std::string getInfo();
};

// ====================================IC======================================

class IC : public StockItem {
private:
    std::string ICtype;
public:
    IC(std::string ICtype, std::string type, std::string code, int number, int pence);
    std::string getInfo();
};

#endif