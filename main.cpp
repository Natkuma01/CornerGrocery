/*
* Name: Shimin Chan
* CS210 - Project Three
* Purpose of the project: 
*/
#include <iostream> 
#include <fstream>
#include <map>
#include <thread>  // for pause
#include <stdexcept>  // for exception handling
#include <cstdlib>  // for cls
#include "grocer.h"

using namespace std;

// global variables
int choice = 0;
int sentinel = 4;


int main() {
    Grocery groceryList;

    groceryList.readInputFile();        
    do {
        
        this_thread::sleep_for(chrono::seconds(1));

        clearScreen();
        
        groceryList.displayMenu();
        groceryList.getValidChoice();
    
        switch (choice) {
            case 1:
                groceryList.findItem();
                break;
            case 2:
                groceryList.displayFrequency();
                break;
            case 3:
                groceryList.showHistogram();
                break;
            case 4:
                exitProgram();
                break;
            default:
                break;
        }// switch

    }//do
while(choice != sentinel);

    
    return 0;
}