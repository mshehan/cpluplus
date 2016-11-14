//  main.cpp
//  List
//
//  Created by Matthew Shehan on 12/11/14.
//  Copyright (c) 2014 Matthew Shehan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "List.h"
#include <string>

void menuDisplay();

int main() {
    
    int size;
    int values;
    int response;
    ifstream in;
    ofstream out;
    string fileName;
    string line;

    
    
    cout << "how many values would you like in the list?: ";
    cin >> size;
    cout << endl;
    
    List<int> myList(size*2);
    
    cout << "Please enter a file name: ";
    cin >> fileName;
    
    
    in.open(fileName.c_str());
    
    if (in.is_open())
    {
        while(getline(in, line))
        {
            cout << line << '\n';
        }
    }
    
    else
        cout << fileName << " was not able to open";
    
    
    // add a switch statement for option
    cout << "would you like to add values to the list?";
    cin >> response;

    
    in >> values; // values to be added to the list if there is space
   
    
    cout << "would you like to see the last value in the list? ";
    cin >> response;
    
    
    cout << "\n" << myList.last() << " is the last value in the list\n";
    
    
    


    out.open("listOut.txt", ios::app);
    
    out.close();
    
    
    
    
    
    
    
    
   
    
    


    
    return 0;
}

/******************************************************************************************************
 Application
You are to write an application (main program) which:
•	Asks the user how many values he/she would like in the list  +
•	Creates a List object with that capacity * 2 +
•	Prompts the user for a filename, and reads values from that file storing them in the list
If file does not exist, list remains empty
•	Prints out the list to the screen, if it is not empty
Otherwise message ‘List is empty’ is printed
•	Allows user to enter more int values if he/she wishes
•	Allows user to view the last value in the list
•	Allow the user to enter a value, and check how many times it occurs in the list
•	Allow the user to enter a value, and remove all occurrances of this from the list
•	Creates a 2nd list, and output it
•	Determines if  two lists are equal
•	Outputs the values from first list to a file (this file should be usable as input for this program)
•	Catches and handles any ListException that is thrown by informing the user of
 ********************************************************************************************************/
