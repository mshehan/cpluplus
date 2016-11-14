/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: February 5, 2015                            *
 * Title: project 2 (Bag/MoneyBag Class)                 *
 * class: CIS 279                                        *
 ********************************************************/

#include <iostream>
#include "MoneyBag.h"

using namespace std;


void printMenu();

int main() {
    
  int choice; // choice value for option menu
  bag::value_type howmany; // how many of each bill
  bag::value_type denom; // the denomination of the bill
  bag::size_type count; // keeps track of the number of bills
  long total; // keeps track of all totals
  
  
  
  MoneyBag uncles_bag;
  
  do{
    printMenu(); // prints a menu for the user
    
    cin >> choice;

    switch(choice)
    {
      case 1: // inserts one bill
      
        cout << "\nwhat is the denomination of the bill" 
          << " you want to insert?: ";
    
        cin >> denom;
        uncles_bag.bag::insert(denom);

        cout << "you inserted one " << denom << "\n";
        break;
      
      case 2: // inserts howmany bills
      
        cout << "\nhow many bills do you want to insert?: ";
        cin >> howmany;
        cout << "\n what is the denomination of the bill?: ";
        cin >> denom;
    
        uncles_bag.insert(howmany, denom);
    
        cout << "you inserted: " << howmany << " " << denom << "s\n";
        break;
    
    
      case 3: // removes one bill from the bag
    
        cout << "what bill would you like to remove from the bag?: ";
        cin >> denom;
        cout << "\n";
    
        uncles_bag.erase_one(denom);
        
        cout << "you just removed one " << denom << "\n";
    
        break;
      
      case 4: // removes all of one denomination of bill
        cout << "what denomination of bill would you like to remove?: ";
        cin >> denom;
        
        uncles_bag.erase(denom);
    
        cout<< "\nall of the " << denom << "s " 
          << "in your money bag have been removed\n";
    
        break;
       
      case 5: // prints the largest bill in the bag to the user
        cout << "the largest bill in the bag is: ";
        cout << uncles_bag.largest();
        cout << "\n";
    
        break;
  
      case 6: // prints the count of a denomination of bill to the screen
        cout << "what denomination would you like to find the count of?"
          << " (ie 1,5,10 or 20): ";
        cin >> denom;
        cout << "\n";
    
        count = uncles_bag.count(denom);
    
        cout << "you have " << count << " number of " << denom 
          << "s in your bag\n";
        
        break;

      case 7: // prints
        cout << "now printing the total in the bag\n";
    
        
        total = uncles_bag.totalAll();
    
        cout << "the total in your bag is: " << total << "\n";
    
        break;

      case 8:
   
        cout << "what denomination of bill would you like to total?: ";
        cin >> denom;
        
        total = uncles_bag.total(denom);
        
        cout << "\nthe total number of " << denom << "s  in your bag is: ";
        cout << total;
        cout << "\n";

        break;

    }
  } while(choice < 9);
  
  
  return 0;
}

void printMenu()
{
  cout <<"\n************************************************************************************" << endl;
  cout << "Please select one of the following options" << endl;
  cout << "1: insert a single bill of denomination 1, 5, 10, or 20: " << endl;
  cout << "2: insert a group of bills of the same denomination (still 1, 5, 10 or 20): " << endl;
  cout << "3: remove a bill from the bag: " << endl;
  cout << "4: remove all of one denomination from the bag: " << endl;
  cout << "5: print out the largest bill in the bag: " << endl;
  cout << "6: print out the number of a denomination (1,5,10 or 20) in the bag: " << endl;
  cout << "7: print out the total amount in the bag: " << endl;
  cout << "8: print out the total of a single denomination in the bag (ie. total of all 10s): " << endl;
  cout << "9: EXIT THE PROGRAM" << endl;
  cout << "************************************************************************************" << endl;
}
