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
#include "StockItem.h"
#include "Inventory.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "========================================" << endl;
    cout << "              StockProgram              " << endl;
    cout << "========================================" << endl;

    cout << "" << endl;

    Inventory *inventory = new Inventory;
    cin >> *inventory; 
    
    string file = "inventory.txt";
    cout << "File to be read: " << file << endl;
    cout << "Reading " << file << "..." << endl;

    cout << "Stock Items successfully saved." << endl;

    cout << "" << endl;

    cout << "There are now " << inventory->getSize() << " Stock Items in the inventory." << endl;

    cout << "" << endl;

    // Print a list of the inventory, sorted in order of increasing price
    
    // What is the component with the largest number of components in stock?

    // How many NPN transistors does Chartlins have in stock?
    cout << "The number of NPN transistors that we have in stock is: " << inventory->getNumberOfNPNTransistors() << endl;


    // What is the total resistance of all of the resistors in stock?
    cout << "The total resistance of all resistors in stock is: ";
    cout << setprecision(12) << inventory->getTotalInStockResistance() << endl;


    // How man stock items have unit prices above 10p?

    cout << "The total number of items that are priced above 10 pence is: ";
    cout << inventory->getTotalStockAboveTenPence(10) << endl;

    return 0;

}




