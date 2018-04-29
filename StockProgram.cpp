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
        cout << "       3. Close                         " << endl;

        cout << "" << endl;
        string option = "";
        cout << "Please chose an option: ";
        cin >> option;
        cout << "" << endl;

        string file = "inventory.txt";
        int sortType = 0;
        int amount = 0;

        if (option == "1") {
            sortType = 1;
            amount = 10;
        } else if (option == "2") {
            cout << "Chose an amount to query the number of Stock Items "
                    "above that amount: ";
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
            cout << "Please chose an option (1, 2, 3, 4): ";
            cin >> sortType;
            cout << "" << endl;

            if (sortType < 1 && sortType > 4) {
                cout << "Invalid selection, sort type set to option 1";
                sortType = 1;
            }
        } else if (option < "1" || option > "2") {
            run = false;
            continue;
        }

        Inventory *inventory = new Inventory;

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
        cout << "Stock Items sorted" << endl;
        cout << "------------------" << endl;
        cout << *inventory;

        /**
         * Question 2 - 
         * What is the component with the largest number of components in stock?
         */
        cout << "The component with the largest stock is: " << endl;
        cout << inventory->largestInStockComponent() << endl;

        /**
         * Question 3 -
         * How many NPN transistors does Chartlins have in stock?
         */
        cout << "The number of NPN transistors that we have in stock is: "
                << inventory->getNumberOfNPNTransistors() << endl;

        /**
         * Question 4 -
         * What is the total resistance of all of the resistors in stock?
         */
        cout << "The total resistance of all resistors in stock is: ";
        cout << setprecision(12) << inventory->getTotalInStockResistance() << endl;

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




