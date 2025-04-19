#pragma once
#ifndef GROCER_H
#define GROCER_H

#include <map>
#include <string>
#include <fstream>

using namespace std;

class Grocery {
    public:
        void displayMenu();
        void readInputFile();
        void findItem();
        void displayFrequency();
        void showHistogram();

    private:
        map<string, int> groceryList;

};
string convert(string text);
void exitProgram();

#endif