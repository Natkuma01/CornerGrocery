/*
* Name: Shimin Chan
* CS210 - Project Three - Corner Grocer
* This project simulates a grocery tracking system that allows users to search specific
* grocery item, backup item sales record, and visualize the data in a histogram format.
*/
#include <iostream> 
#include <fstream>
#include <map>
#include <thread>       // for pause the screen
#include <stdexcept>    // for exception handling
#include "grocer.h"

using namespace std;

// set global variables for all access
int choice = 0;         // store user's menu selection
int sentinel = 4;       // set sentinel value to control when to exist the program loop


int main() {
    Grocery groceryList;                // create an instance of Grocery class

    groceryList.readInputFile();        // read input data file and load item frequency for backup
    
    // start the program loop
    do {
        
        this_thread::sleep_for(chrono::seconds(1));     // add one sec to smooth user experience

        clearScreen();
        
        groceryList.displayMenu();       // display menu options
        choice = groceryList.getValidChoice();    // ensure user's input is numeric and inside the range       
    
        // perform an action based on user's choice
        switch (choice) {                
            case 1:
                groceryList.findItem();             // show specific item with its frequency
                break;
            case 2:
                groceryList.displayFrequency();     // show all items and frequencies
                break;
            case 3:
                groceryList.showHistogram();        // show item frequencies in a histogram format
                break;
            case 4:
                exitProgram();                      // exit the program
                break;
            default:
                break;
        }// switch

    }//do
    while(choice != sentinel);          // repeat the loop until user want to exit

    
    return 0;
}//main