/* 
 * File:   StockItem.h
 * Author: Parkesy
 *
 * Created on 19 April 2018, 12:20
 */

#include <string>
#include <vector>

#ifndef StockItem_H
#define StockItem_H

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
    inline std::string getType();
    inline std::string getCode();
    inline int getStock();
    inline int getPrice();
    virtual std::string getInfo() = 0;
    inline void setType(std::string type);
    inline void setCode(std::string code);
    inline void setStock(int stock);
    virtual void setInfo() = 0;
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

// ===============================RESISTOR=====================================

class Resistor : public StockItem {
private:
    std::string resistance;
public:
    Resistor(std::string resistance, std::string type, std::string code,
            int number, int pence);
    double getNumericalResistance();
    std::string getInfo();
    void setInfo();
};

// ===============================CAPACITOR====================================

class Capacitor : public StockItem {
private:
    std::string capacitance;
public:
    Capacitor(std::string capacitance, std::string type, std::string code,
            int number, int pence);
    std::string getInfo();
    void setInfo();
};

// ==================================DIODE=====================================

class Diode : public StockItem {
public:
    Diode(std::string type, std::string code, int number, int pence);
    std::string getInfo();
    void setInfo();
};

// ===============================TRANSISTOR===================================

class Transistor : public StockItem {
private:
    std::string transistorType;
public:
    Transistor(std::string transistorType, std::string type, std::string code, int number, int pence);
    std::string getInfo();
    void setInfo();
};

// ====================================IC======================================

class IC : public StockItem {
private:
    std::string ICtype;
public:
    IC(std::string ICtype, std::string type, std::string code, int number, int pence);
    std::string getInfo();
    void setInfo();
};

#endif