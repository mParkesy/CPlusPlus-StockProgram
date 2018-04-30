/* 
 * File:   main.cpp
 * Author: Parkesy
 *
 * Created on 19 April 2018, 11:18
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fcntl.h>
#include <io.h>
#include "StockItem.h"
#include "Inventory.h"
using namespace std;

int main(int argc, char** argv) {
    bool run = true;
    while (run) {
        cout << "========================================" << endl;
        cout << "              StockProgram              " << endl;
        cout << "========================================" << endl;
        cout << "                  Menu                  " << endl;
        cout << "                  ----                  " << endl;
        cout << "       1. Load assignment queries       " << endl;
        cout << "       2. Input queries                 " << endl;
        cout << "       3. Run Tests                     " << endl;
        cout << "       4. Close                         " << endl;

        cout << "" << endl;
        string option = "";
        cout << "Please chose an option: ";
        cin >> option;
        cout << "" << endl;

        string file = "inventory.txt";
        int sortType = 0;
        int amount = 0;
        string search = "";

        if (option == "1") {
            sortType = 1;
            amount = 10;
            search = "NPN";
        } else if (option == "2") {
            cout << "Type an amount to query the number of Stock Items "
                    "above that amount (pence): ";
            cin >> amount;
            cout << "" << endl;

            cout << "                Sorting Menu             " << endl;
            cout << "                ------------             " << endl;
            cout << "       1. Sort by Price descending       " << endl;
            cout << "       2. Sort by Price ascending        " << endl;
            cout << "       3. Sort by Type A-Z               " << endl;
            cout << "       4. Sort by Code A-Z               " << endl;
            cout << "       5. Sort by Stock Amount descending" << endl;
            cout << "       6. Sort by Stock Amount ascending " << endl;
            cout << "" << endl;
            cout << "Please chose a search type (1, 2, 3, 4, 5, 6): ";
            cin >> sortType;
            cout << "" << endl;

            if (sortType < 1 && sortType > 4) {
                cout << "Invalid selection, sort type set to option 1";
                sortType = 1;
            }
            
            cout << "Please type a string to get the number of StockItems "
                    "with that additional information field: ";
            cin >> search;
        } else if(option == "3"){                
            cout << "Resistor, RES_1R0, 41, 1, 1R0 has been "
                    "instantiated." << endl;
            Resistor *r = new Resistor("1R0", "resistor" , "RES_1R0", 
                    stoi("41") , stoi("1"));
            
            cout << "Transistor, BC108,    9, 12, NPN has been "
                    "instantiated." << endl;
            Transistor *t = new Transistor("NPN", "transistor", "BC108", 
                    stoi("9"), stoi("12"));
            
            cout << "Capacitor, CAP_150pF, 200, 20, 150pF has been "
                    "instantiated." << endl;
            Capacitor *c = new Capacitor("150pF", "capacitor", "CAP_150pF", 
                    stoi("200"), stoi("20"));
            
            cout << "Diode, 1N4001,  208, 4 has been "
                    "instantiated." << endl;
            Diode *d = new Diode("diode", "1N4001", stoi("208"), stoi("4"));
            
            cout << "IC, NE555,  8, 17,  Timer has been "
                    "instantiated." << endl;
            IC *ic = new IC("Timer", "IC", "NE555", stoi("8"), stoi("7"));
            
            cout << endl;
            cout << "Testing getters for StockItem:" << endl;
            cout << "Type:  " << r->getType() << endl;
            cout << "Code:  " << r->getCode() << endl;
            cout << "Stock: " << r->getQuantity() << endl;
            cout << "Price: " << r->getPrice() << endl;
            cout << "Additional Information:  " << r->getInfo() << endl;
            cout << "Resistance: " << r->getResistance() <<endl;
             
            cout << "\nNew Inventory Created." << endl;    
            Inventory *i = new Inventory();
            cout << i->getSize() <<" StockItems added to Inventory" << endl;
            i->addStock(r);
            i->addStock(t);
            i->addStock(c);
            i->addStock(d);
            i->addStock(ic);
            
            cout << "\nInventory printed: " << endl;
            cout << *i;
       
            cout << "Getting StockItem in position one of Inventory:" << endl;
            StockItem &item = i->getStock(0);
            cout << item;
            
            cout << "\nRemoving StockItem in position one of Inventory:" << endl;
            i->removeStock(0);
                        
            cout << "There are " << i->getSize() << " StockItems in "
                    "the Inventory." << endl;
            
            cout << "\nPlease load assignment queries to see "
                    "other tests." << endl;
            cout << endl;
            continue;
        } else if (option < "1" || option > "3") {
            run = false;
            cout << "Program closed" << endl;
            continue;
        }

        Inventory *inventory = new Inventory();

        //file = removeCharacters(file);
        inventory->setFile(file);

        cin >> *inventory;

        cout << "File to be read: " << file << endl;
        cout << "Reading " << file << "..." << endl;

        cout << "Stock Items successfully saved." << endl;

        cout << "" << endl;

        cout << "There are now " << inventory->getSize() << " Stock Items in "
                "the inventory." << endl;

        cout << "" << endl;

        /**
         * Question 1 - 
         * Print a list of the inventory, sorted in order of increasing price
         */
        inventory->sortInv(sortType);
        cout << "Stock Items sorted by sort type " << sortType << endl;
        cout << "------------------" << endl;
        cout << *inventory;

        /**
         * Question 2 - 
         * What is the component with the largest number of components in stock?
         */
        cout << "The component with the largest stock amount is: " << endl;
        cout << inventory->HighestStock() << endl;

        /**
         * Question 3 -
         * How many NPN transistors does Chartlins have in stock?
         */
        cout << "The number of " << search << " transistors that we have "
                "in stock is: "
                << inventory->searchInfo(search) << endl;

        /**
         * Question 4 -
         * What is the total resistance of all of the resistors in stock?
         */
        cout << "The total resistance of all resistors in stock is: ";
        cout << setprecision(16) << 
                inventory->getTotalInStockResistance() << endl;

        /**
         * Question 5 -
         * How man stock items have unit prices above 10p?
         */
        cout << "The total number of items that are priced above " << amount <<
                " pence is: ";
        cout << inventory->getTotalStockAbovePrice(amount) << endl;
    }
    return 0;

}




