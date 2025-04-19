#pragma once
#ifndef GROCER_H
#define GROCER_H

#include <map>
#include <string>
#include <fstream>

using namespace std;


map<string, int> readInputFile(ifstream &inputFile);

void displayMenu();


#endif