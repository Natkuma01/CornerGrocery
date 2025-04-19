/*
* Name: Shimin Chan
* CS210 - Project Three
* Purpose of the project: 
*/
#include <iostream> 
#include <fstream>
#include <map>
#include "grocer.h"

using namespace std;
          


int main() {
    int choice;
    Grocery groceryList;

    groceryList.readInputFile();        

    groceryList.displayMenu();

    cin >> choice;
    
    switch (choice) {
        case 1:
            groceryList.findItem();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }// switch


    
    return 0;
}