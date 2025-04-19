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

string convert(string text){
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

void Grocery::readInputFile() {
    ifstream inFile;
    ofstream outFile;
    string item;

    inFile.open("itemsRecord.txt");       // read from the text file
    if (!inFile.is_open()) {
        cout << "Could not open itemsRecord.txt" << endl;
    } //if
    
    while (getline(inFile, item)) {
        string lowercase = convert(item);
        groceryList[lowercase]++;        
        
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
    string userInput;
    string item;

    cout << "Enter the item you are looking for: " << endl;

    cin >> userInput;
    item = convert(userInput);

    auto result = groceryList.find(item);
    if (result != groceryList.end()) {
        cout << result->first << " " << result->second << endl;
    }
    else {
        cout << "No such item." << endl;
    }

}

void Grocery::displayFrequency() {
    for (auto &data : groceryList) {
        cout << data.first << " " << data.second << endl;
    }
}

void Grocery::showHistogram() {
    for (auto &data : groceryList) {
        cout << data.first << " " << string(data.second, '*') << endl;
    }
}

void exitProgram() {
    cin.get();
}