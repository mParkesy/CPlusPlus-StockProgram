/* 
 * File:        StockItem.h
 * Author:      100116544
 * Description: Header file for StockItem class which consists
 *              of a type, code, stock amount and price.
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
    int quantity;
    int price;

public:
    /**
     * Default constructor that creates a new StockItem object
     */
    StockItem();

    /**
     * A standard constructor that takes two strings and two integers
     * as parameters to create a new StockItem object
     * @param type - The type of StockItem as a string
     * @param code - The code of the StockItem as a string
     * @param number - The number of StockItem in stock as an integer
     * @param pence - The cost of the StockItem as an integer
     */
    StockItem(std::string type, std::string code, int number, int pence);

    StockItem(const StockItem& orig);
    virtual ~StockItem();

    /**
     * Gets the type of StockItem for the current instance
     * @return A string containing the StockItem type
     */
    inline std::string getType() const;

    /**
     * Gets the code of the StockItem for the current instance
     * @return A string containing the StockItem code
     */
    inline std::string getCode() const;

    /**
     * Gets the amount of stock for the current StockItem instance
     * @return An integer containing the stock amount
     */
    inline int getQuantity() const;

    /**
     * Gets the price of the StockItem for the current instance
     * @return An integer containing the StockItem price in pence
     */
    inline int getPrice() const;

    /**
     * A pure virtual method that will be implemented for each derived class
     * to return the additional information for each StockItem type
     * @return A string containing the StockItems additional information
     */
    virtual std::string getInfo() const = 0;

    /**
     * Sets the StockItem type for the current StockItem instance
     * @param type - A string containing the new StockItem type to be set
     */
    inline void setType(std::string type);

    /**
     * Sets the StockItem code for the current StockItem instance
     * @param code - A string containing the new StockItem code to be set
     */
    inline void setCode(std::string code);

    /**
     * Sets the StockItem amount of stock for the current StockItem instance
     * @param stock - An integer containing the new StockItem amount to be set
     */
    inline void setQuantity(int stock);

    /**
     * Grants a separate function or class access to private
     * members of the current class
     */
    friend std::ostream& operator<<(std::ostream &os, const StockItem &item);
};

inline std::string StockItem::getType() const {
    return this -> itemType;
}

inline std::string StockItem::getCode() const {
    return this -> stockCode;
}

inline int StockItem::getQuantity() const {
    return this -> quantity;
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

inline void StockItem::setQuantity(int stock) {
    this->quantity = stock;
}

/**
 * Overload the << output stream operator so that a StockItem can
 * be printed in a suitable format
 * @param os - Reference to the output stream 
 * @param inv - Reference to the StockItem object which is to be printed
 * @return A reference to the output stream containing the StockItem object 
 */
inline std::ostream& operator<<(std::ostream &os, const StockItem &item) {
    return os << "Type:  " << item.itemType << "\n"
            << "Code:  " << item.stockCode << "\n"
            << "Stock: " << item.quantity << "\n"
            << "Price: " << item.price << "\n"
            << "Additional Information: " << item.getInfo() << "\n";
}

// ===============================RESISTOR=====================================

/**
 * A derived class of type Resistor which stores an additional string
 * field which contains the resistors resistance
 */
class Resistor : public StockItem {
private:
    std::string resistance;
public:
    /**
     * A constructor that calls on the StockItem constructor along with the
     * additional resistance field for Resistor
     * @param resistance - A string containing the resistance value
     * @param type - The type of StockItem as a string
     * @param code - The code of the StockItem as a string
     * @param number - The number of StockItem in stock as an integer
     * @param pence - The cost of the StockItem as an integer
     */
    Resistor(std::string resistance, std::string type, std::string code,
            int number, int pence);

    /**
     * An implementation of the virtual method for the derived class Resistor,
     * the method converts the Resistance value in its standard form to a 
     * decimal digit in Ohms
     * @return A string containing the decimal value of the Resistor in Ohms
     */
    std::string getInfo() const;
    
    /**
     * Calculates the decimal value for the Resistor in ohms
     * @return The decimal ohms value as a double
     */
    double getResistance() const;
};


// ===============================CAPACITOR====================================

/**
 * A derived class of type Capacitor which stores an additional string
 * field which contains the capacitors capacitance
 */
class Capacitor : public StockItem {
private:
    std::string capacitance;
public:
    /**
     * A constructor that calls on the StockItem constructor along with the
     * additional capacitance field for Capacitor
     * @param capacitance - A string containing the capacitance value
     * @param type - The type of StockItem as a string
     * @param code - The code of the StockItem as a string
     * @param number - The number of StockItem in stock as an integer
     * @param pence - The cost of the StockItem as an integer
     */
    Capacitor(std::string capacitance, std::string type, std::string code,
            int number, int pence);

    /**
     * An implementation of the virtual method for the derived class Capacitor
     * @return A string containing the capacitance of the capacitor
     */
    std::string getInfo() const;
};

// ==================================DIODE=====================================

/**
 * A derived class of type Diode which holds no additional information
 */
class Diode : public StockItem {
public:

    /**
     * A constructor that calls on the StockItem constructor
     * @param type - The type of StockItem as a string
     * @param code - The code of the StockItem as a string
     * @param number - The number of StockItem in stock as an integer
     * @param pence - The cost of the StockItem as an integer
     */
    Diode(std::string type, std::string code, int number, int pence);

    /**
     * An implementation of the virtual method for the derived class Diode
     * @return A blank string due to a Diode containing 
     * no additional information
     */
    std::string getInfo() const;
};

// ===============================TRANSISTOR===================================

/**
 * A derived class of type Transistor which stores an additional string
 * field which contains the transistors type
 */
class Transistor : public StockItem {
private:
    std::string transistorType;
public:
    /**
     * A constructor that calls on the StockItem constructor along with the
     * additional transistor type field for Transistor
     * @param transistorType - A string containing the transistor type
     * @param type - The type of StockItem as a string
     * @param code - The code of the StockItem as a string
     * @param number - The number of StockItem in stock as an integer
     * @param pence - The cost of the StockItem as an integer
     */
    Transistor(std::string transistorType, std::string type, std::string code,
            int number, int pence);

    /**
     * An implementation of the virtual method for the derived class Transistor
     * @return A string containing the transistor type
     */
    std::string getInfo() const;
};

// ====================================IC======================================

/**
 * A derived class of type Internal Circuit which stores an additional string
 * field which contains the Internal Circuits type
 */
class IC : public StockItem {
private:
    std::string ICtype;
public:
    /**
     * A constructor that calls on the StockItem constructor along with the
     * additional Internal Circuit type field for Internal Circuits
     * @param ICtype - A string containing the IC type
     * @param type - The type of StockItem as a string
     * @param code - The code of the StockItem as a string
     * @param number - The number of StockItem in stock as an integer
     * @param pence - The cost of the StockItem as an integer
     */
    IC(std::string ICtype, std::string type, std::string code,
            int number, int pence);
    
    /**
     * An implementation of the virtual method for the derived class IC
     * @return A string containing the Internal Circuit type
     */
    std::string getInfo() const ;
};

#endif