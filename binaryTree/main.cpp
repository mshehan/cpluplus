/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: April 21st, 2015                            *
 * Title: project 5                                      *
 * class: CIS 279                                        *
 ********************************************************/
#include <iostream>
#include "Collection.h"
#include "CD.h"

using namespace std;

void printMenu();
int main() {
  int choice = 0; // used to choose from printMenu
  
  string title; // following used for adding information the the CD
  string author;
  int quantity;
  int cost;
  
  
  Collection<CD> library;
  
  cout << "welcome to the CD library.\n";
  cout << "please choose one of the following options to continue\n\n";
  
  while(choice >= 0){
    
    printMenu(); // prints the CD menu to the screen
    cin >> choice;

    switch(choice)
    {
      case 1: // insert a new CD into the collection
      {
        cin.ignore();
        cout << "please type the title of the CD: ";
        getline(cin, title);
        
        
        cout << "\nplease type the author of the CD: ";
        getline(cin,author);
        
        cout << "\nplease enter the quantity: ";
        cin >> quantity;
    
        cout << "\nfinally, please enter the cost:";
        cin >> cost;
        cout <<"\n\n";
    
        cout << "creating new CD object...\n";
        CD add(title,author,quantity,cost);
    
        library.insert(add);
        cout << "new CD object added\n\n";
        break;
      }
      case 2: // prints all the CDs in the collection
      {
        cout << "Here are all the CDs in your collection:\n";
        library.printTree();
        break;
      }
      case 3: // checks the existance of CD object in collection class
      {
        cout << "please provide the title of the CD you are checking for: ";
        cin.ignore();
        getline(cin,title);
          if(library.isThere(CD(title)))
          {
            cout << "\n" << title 
              << " was found in the collection\n\n";
          }
          else
          {
            cout << "\n" << title 
              << " was not found in the collection\n\n";
          }
        break;
      }
      case 4: // updates the CD in the collection that you search for
      {
        cout << "please provide the title of the CD" 
          << " you are trying to update: ";
        
        cin.ignore();
        getline(cin,title);
        if(!library.isThere(title))
        {
          cout << "\nthis title does not exist in the collection\n\n";
        }
        else
        {
          CD temp = library.getItem(CD(title));
          
          cout<< "\nplease enter the name of the updated author: ";
          
          getline(cin,author);
          
          cout << "\nplease enter the updated quanity of the CD: ";
          cin >> quantity;
          cout <<"\nplease enter the updated cost of the CD: ";
          cin >> cost;
          cout << "\n\n";
          
          library.update(temp,CD(title,author,quantity,cost));
        }
        break;
      }
      case 5:// prints out the size of the collection
      {
        cout << "you have a collection with " << library.size() 
          << " items\n\n";
        break;
      }
      case 6: // quits the program
      {
        cout << "quitting the program...";
        exit(1);
        break;
      }
    }
  }

  

  return 0;
}

void printMenu()
{
    cout << "*********************************************************\n";
    cout << "1: insert a new CD into your collection\n\n";
    cout << "2: print out all the CDs in your collection\n\n";
    cout << "3: check to see if the CD exists in your collection\n\n";
    cout << "4: update one of the CDs in your collection\n\n";
    cout << "5: print out the number of CDs in your collection\n\n";
    cout << "6: quit the program\n";
    cout << "*********************************************************\n\n";
}
