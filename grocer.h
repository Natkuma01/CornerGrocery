#pragma once
#ifndef GROCER_H
#define GROCER_H

using namespace std;

// declare global variables so they can be accessed across multiple files
extern int choice;                          //store user's menu selection
extern int sentinel;                        // sentinel values used to control program loop



class Grocery {
    public:
        void displayMenu();                 // display menu options
        void readInputFile();               // read item data from input file, store frequencies in map<>GroceryList, and create backup file
        void findItem();                    // search for a specific grocery item and show its purchased frequency
        void displayFrequency();            // show all grocery items and their purchased frequencies
        void showHistogram();               // show item frequency in a histogram format
        int getValidChoice();               // ensure user input for menu choice is validated

    private:
        map<string, int> groceryList;       // store grocery item names and their corresponding counts

};

string convert(string text);                // convert a string to lowercase
void exitProgram();                         // handle program exit
bool isAlphabetOnly(string userInput);      // check if a string contain non-alphabet character
void clearScreen();                         // clear console screen for better readability

#endif