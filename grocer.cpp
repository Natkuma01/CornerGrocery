#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include "grocer.h"

using namespace std;


void displayMenu() {
    cout << "******************** MENU CHOICES *********************" << endl;
    cout << " [1] Find Yout Grocery Item" << endl;
    cout << " [2] Display Grocery Item And Purchase Frequency" << endl;
    cout << " [3] Display Grocery Items In Histogram" << endl;
    cout << " [4] Exit Program" << endl;
    cout << "********************************************************" << endl;
}



map<string, int> readInputFile(ifstream &inputFile) {
    map<string, int> groceryList;
    ifstream inFile;
    ofstream outFile;
    string item;

    cout << "RUN";
    inFile.open("itemsRecord.txt");       // read from the text file
    if (!inFile.is_open()) {
        cout << "Could not open itemsRecord.txt" << endl;
        return groceryList;
    } //if
    
    while (getline(inFile, item)) {
        groceryList[item]++;        
        
    }//while

    inFile.close();


    outFile.open("frequency.dat");
    if (!outFile.is_open()) {
        cout << "Could not generate the grocery list." << endl;
        return groceryList;
    }

    for (const auto& data : groceryList) {
        outFile << data.first << " " << data.second << endl;
    }

    outFile.close();
    return groceryList;

}