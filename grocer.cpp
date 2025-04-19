#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include "grocer.h"

using namespace std;


void Grocery::displayMenu() {
    cout << "******************** MENU CHOICES *********************" << endl;
    cout << " [1] Find Yout Grocery Item" << endl;
    cout << " [2] Display Grocery Item And Purchase Frequency" << endl;
    cout << " [3] Display Grocery Items In Histogram" << endl;
    cout << " [4] Exit Program" << endl;
    cout << "********************************************************" << endl;
}



void Grocery::readInputFile() {
    map<string, int> groceryList;
    ifstream inFile;
    ofstream outFile;
    string item;

    cout << "RUN";
    inFile.open("itemsRecord.txt");       // read from the text file
    if (!inFile.is_open()) {
        cout << "Could not open itemsRecord.txt" << endl;
    } //if
    
    while (getline(inFile, item)) {
        groceryList[item]++;        
        
    }//while

    inFile.close();

    outFile.open("frequency.dat");
    if (!outFile.is_open()) {
        cout << "Could not generate the grocery list." << endl;
    }

    for (const auto& data : groceryList) {
        outFile << data.first << " " << data.second << endl;
    }

    outFile.close();

}

void Grocery::findItem() {
    string item;

    cout << "Enter the item you are looking for: " << endl;

    cin >> item;

    auto result =  groceryList.find(item);
    if (result != groceryList.end()) {
        cout << result->first << " " << result->second << endl;
    }
    else {
        cout << "No such item." << endl;
    }

}