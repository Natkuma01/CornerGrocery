#include <iostream>
#include <iomanip>   // for setw()
#include <thread>
#include <map>
#include <fstream>
#include <cctype>       // for isAlphaOnly()
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

bool isAlphabetOnly(string userInput){
    for (char letter : userInput) {
        if (!isalpha(letter)) {
            return false;
        }
    }
    return true;
}

void Grocery::findItem() {
    string userInput;
    string item;                   
    bool  itemFound= false;

    while(!itemFound) { 
    cout << "Enter the item name (e.g. apples, garlic, onions): " << endl;

    cin >> userInput;
    item = convert(userInput);
    if (!isAlphabetOnly(userInput)) {                   // if wrong data type
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter grocery item name in English." << endl;
        continue;
    }
    
    auto result = groceryList.find(item);
    if (result != groceryList.end()) {
        cout << result->first << " " << result->second << endl;
        itemFound = true;
    }
    else {
        cout << "No such item." << endl;
    }
}//while

}


void Grocery::displayFrequency() {
    for (auto &data : groceryList) {
        cout << data.first << " " << data.second << endl;
    }
}

void Grocery::showHistogram() {
    for (auto &data : groceryList) {
        cout << setw(16) << right << data.first << "    "; 
        cout << string(data.second, '*') << endl;
    }
    this_thread::sleep_for(chrono::seconds(2));
}

void exitProgram() {
    cin.get();
}

int Grocery::getValidChoice() {
    bool notValid = true;
    while(notValid) {
    try {
        cout << "Enter your choice: " << endl;
        cin >> choice;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            throw invalid_argument("Please enter a valid number");
        }//if
        else if (choice < 0 || choice > sentinel) {
            string msg = "Please enter number between 1 to ";
            throw out_of_range(msg + to_string(sentinel));
        }//else if
        else {
            notValid = false;
        }//else
    }//try
    catch (const invalid_argument& e) {
        cout << "Invalid input: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cout << "Your input is out of range: " << e.what() << endl;
    }
    catch (...) {
        cout << "Your input is not accepted at this time. Try again later." << endl;
    }
    }//while
    return choice;
}

void clearScreen() {
    cout << "\033[2J\033[H";
    cout.flush();
}