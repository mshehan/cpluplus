/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: February 10, 2015                           *
 * Title: project 4 (GStack, StringEditor Class)         *
 * class: CIS 279                                        *
 ********************************************************/
#include <iostream>
#include "StringEditor.h"

using namespace std;
void printMenu();
int main()
{
  int choice; // holds the value of the user's choice.
  string left; // holds the string to the left of the cursor
  string right;
  // used to fullfil constructor param requirements
  // never actually stores values from the user.
  cout << "Hello and Welcome to the String Editor Class Program" << endl;
  cout << "let's start. Please enter the string you would like to edit: " 
    << endl;
  
  getline(cin,left);
  StringEditor theString = StringEditor(left,right);
  cout << theString;
  do
  {
    printMenu(); // prints String Editor menu to the user
    cin >> choice;
    switch(choice)
    {
      case 1: // inserts character
        char insertChar;
        cout<< "you've chosen to insert a character at the cursor's"
          << " position" << endl;
        cout << "what character would you like to enter?: ";
        cin >> insertChar;
        cout << endl;
        theString.insertChar(insertChar);
        cout << "you inserted " << insertChar 
          << " at the cursor's position\n";
        cout << "here's the new string: " << endl;
        
        cout << theString << endl;
        break;
          
      case 2: // move the cursor the right one position
        
        cout << "you've chosen to move the cursor the right one position" 
          << endl;
        
        theString.moveCursorRight();
        
        cout << "here's the new positon of the cursor: " << endl;
        cout << theString;
        
        break;
          
      case 3: // moves cursor the left one position
        cout << "you've chosen to move the cursor the left one position" 
          << endl;
        theString.moveCursorLeft();
        cout << "here's the new positon of the cursor: " << endl;
        cout << theString << endl;
        
        break;
          
      case 4: // moves cursor to front
        cout << "you've chosen to move the cursor the front" << endl;
        theString.frontOfString();
        cout << "here's the new positon of the cursor: " << endl;
        cout << theString << endl;
        break;
      case 5:// moves cursor to rear
        cout << "you've chosen to move the cursor the rear" << endl;
        theString.endOfString();
        cout << "here's the new positon of the cursor: " << endl;
        cout << theString << endl;
        break;
      case 6: // deletes char ahead of cursor
        cout << "you've chosen to delete the character directly following the cursor" << endl;
        theString.deleteChar();
        cout << "here's the new string: " << endl;
        cout << theString << endl;
        break;
      case 7: // deletes char preceding cursor
        cout << "you've chosen to backspace"
          << " (delete the character directly preceding the cursor)" 
          << endl;
        theString.backspace();
        cout << "here's the new string: " << endl;
        cout << theString << endl;
        break;
        
      case 8: // quits the program
        cout << "Thank You for using the String Editor class"<< endl;
        cout << "now quitting..." << endl;
        exit(1);
        break;
      }
  }while(choice < 9);
}

void printMenu()
{
    cout <<"\n******************************************"
      <<"*****************************";
    cout<< "\nselect one of the following options."<<endl;
    cout << "1: insert a character at the cursor's position" << endl;
    cout << "2: move the cursor to the right one position" << endl;
    cout << "3: move the cursor to the left one position" << endl;
    cout << "4: move the cursor the the front of the string" << endl;
    cout << "5: move the cursor to the rear of the string" << endl;
    cout << "6: delete the character directly following the cursor" << endl;
    cout << "7: backspace (remove) the character directly preceding"
      << " the cursor" << endl;
    cout << "8: quit the program" << endl;
    cout <<"*******************************************
      << "****************************";
    cout << endl;
}
