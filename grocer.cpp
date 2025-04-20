#include <iostream>
#include <iomanip>      // for setw()
#include <thread>       // for sleep functionality
#include <map>
#include <fstream>
#include <cctype>       // for isAlphaOnly()
#include "grocer.h"

using namespace std;


// display the menu choices to user
void Grocery::displayMenu() {
    cout << "******************** MENU CHOICES *********************" << endl;
    cout << " [1] Find Yout Grocery Item" << endl;
    cout << " [2] Display Grocery Item And Purchase Frequency" << endl;
    cout << " [3] Display Grocery Items In Histogram" << endl;
    cout << " [4] Exit Program" << endl;
    cout << "********************************************************" << endl;
}//displayMenu


// convert a string to all lowercase for case-sensitive comparison
string convert(string text){
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}//convert


// read item names from a file, count frequencies, and save a backup data to another file
void Grocery::readInputFile() {
    ifstream inFile;
    ofstream outFile;
    string item;

    inFile.open("itemsRecord.txt");         // open input file       
    if (!inFile.is_open()) {                // if unable to open the file
        cout << "Could not open itemsRecord.txt" << endl;
    } //if
    
    // read each item and update frequency in the map until the end of the input file
    while (getline(inFile, item)) {
        string lowercase = convert(item);   // convert the item's name to lowercase
        groceryList[lowercase]++;           // increase count        
        
    }//while

    inFile.close();                         // close input file

    // open output file to store item name and frequencies data
    outFile.open("frequency.dat");
    if (!outFile.is_open()) {
        cout << "Could not generate the grocery list." << endl;
    }//if

    // write grequencies into the output file
    for (const auto& data : groceryList) {
        outFile << data.first << " " << data.second << endl;
    }//for

    outFile.close();                        // close output file

}//readInputFile


// this function specific for findItem() 
// cin reads numeric input as valid string, cin.fail() won't catch them
bool isAlphabetOnly(string userInput){
    for (char letter : userInput) {         // loop through each letter of user input
        if (!isalpha(letter)) {
            return false;
        }//if
    }//for
    return true;
}//isAlphabetOnly


// find a specific item entered by the user and show its frequency
void Grocery::findItem() {
    string userInput;
    string item;                   
    bool  itemFound= false;                 // flag to track whether a matching item is found in groceryList

    // loop continues until the user enters a valid grocery item that exists in the map
    while(!itemFound) {                  
    cout << "Enter the item name (e.g. apples, garlic, onions): " << endl;

    cin >> userInput;
    item = convert(userInput);              // convert user input to lowercase
    if (!isAlphabetOnly(userInput)) {       // if there's non alphabet element in user input            
        cin.clear();                        // clear any error flags in cin
        cin.ignore(100, '\n');              // ignore up to 100 character or until new line
        cout << "Please enter grocery item name in English." << endl;
        continue;                           // restart loop to prompt for valid input
    }//if
    
    auto result = groceryList.find(item);   // look up item in the groceryList
    
    if (result != groceryList.end()) {      // if item found
        cout << result->first << " " << result->second << endl;     // print item name and its frequency
        itemFound = true;                   // stop the loop
    }//if
    
    else {                                  // if item not found, display error message
        cout << "No such item." << endl;
    }//else

    }//while
}//findItem


// display all grocery items and their purchase frequencies
void Grocery::displayFrequency() {
    for (auto &data : groceryList) {
        cout << data.first << " " << data.second << endl;
    }//for
}//displayFrequency


// display a histogram of item purchase frequencies
void Grocery::showHistogram() {
    for (auto &data : groceryList) {
        cout << setw(16) << right << data.first << "    "; 
        cout << string(data.second, '|') << endl;
    }//for
    this_thread::sleep_for(chrono::seconds(2));        // smal delay after showing histogram
}//showHistogram


// exit program function
void exitProgram() {
    cin.get();
}

// get and validate user's menu choice input
int Grocery::getValidChoice() {
    bool notValid = true;                       // assume not valid, flag to keep track if the input is valid
    while(notValid) {                           // continue prompting user until a valid choice is entered
    try {
        cout << "Enter your choice: " << endl;
        cin >> choice;

        if(cin.fail()) {                        // ensure input data type is numeric
            cin.clear();
            cin.ignore(100, '\n');
            throw invalid_argument("Please enter a valid number");
        }//if
        else if (choice < 0 || choice > sentinel) {     // ensure input is within the range 
            string msg = "Please enter number between 1 to ";
            throw out_of_range(msg + to_string(sentinel));      // trigger exception with range info
        }//else if
        else {
            notValid = false;                   // exit the lopp when input satisfied numeric data type and within range
        }//else
    }//try

    // handle case when user input is not a number
    catch (const invalid_argument& e) {
        cout << "Invalid input: " << e.what() << endl;
    }

    // handle case when user input is a number but not in the valid range (1 to 4)
    catch (const out_of_range& e) {
        cout << "Your input is out of range: " << e.what() << endl;
    }

    // handle all other cases for any unexpected exception types
    catch (...) {
        cout << "Your input is not accepted at this time. Try again later." << endl;
    }
    }//while
    return choice;              // return validated user input
}

// clear screen for smooth user experience
void clearScreen() {
    cout << "\033[2J\033[H";
    cout.flush();
}