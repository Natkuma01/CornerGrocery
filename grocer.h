#pragma once
#ifndef GROCER_H
#define GROCER_H

using namespace std;

extern int choice;
extern int sentinel;



class Grocery {
    public:
        void displayMenu();
        void readInputFile();
        void findItem();
        void displayFrequency();
        void showHistogram();
        int getValidChoice();

    private:
        map<string, int> groceryList;

};

string convert(string text);
void exitProgram();
bool isAlphabetOnly(string userInput);
void clearScreen();

#endif