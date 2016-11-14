/*
 * Name: Matthew Shehan                                  *
 * Due Date: May 12, 2015                                *
 * Title: project 7                                      *
 * class: CIS 279                                        *
 
 The Main Program
 -----------------
 The main program has a few simple functions.
 Users can choose
 1. to add a new customer to the table
 2. retrieve their information
 3. delete the customer from the table
 4. to quit the program
 
 This program uses the node class and
 the table class to store objects of type customer
 */

#include <iostream>
#include "table2.h"
#include "Customer.h"

void printMenu();

int main()
{
 int phone;
  std::string name;
  std::string address;
  int choice;
  
  table<Customer> pizzaList;
  
  
  
  do{
    printMenu();
    cin >> choice;
    switch(choice)
    {
      case 1:
      {
        cin.ignore();
        cout << "please enter the customer's name: ";
        
        getline(cin,name);
        cout << "\n";
        
        cout << "please enter the customer's address: ";
        getline(cin,address);
        cout << "\n";
        
        cout << "please enter the customer's phone number: ";
        cin >> phone;
        cout << "\n";
        
        Customer pizzaOrder(name, address, phone);
        
        pizzaList.insert(pizzaOrder);
        break;
      }
      case 2:
      {
        bool isThere;
        cout << "to find the customer's information " 
          << "please enter their phone number: ";
        cin >> phone;
        cout << "\n";
        
        Customer print;
       
        pizzaList.find(phone, isThere, print);
        
        if(isThere)
            cout << print << "\n";
        else
            cout << "customer not found\n";
        break;
      }
      case 3:
      {
        cout << "please enter the phone number of the customer" 
          << " you'd like to remove\n";
        cin >> phone;
        cout << "\n";
        pizzaList.remove(phone);
        
        cout << "customer has been removed\n";
        break;
      }
      case 4:
      {
        cout << "exiting program\n";
        exit(1);
      }
            
    }
    
  }while(choice <= 4);
   
}

void printMenu()
{
    cout << "---------------------------------------\n";
    cout << "please choose from the selection below\n";
    cout << "1: add a new customer\n";
    cout << "2: retrieve a customer's information\n";
    cout << "3: delete a customer\n";
    cout << "4: exit program\n";
    cout << "----------------------------------------\n\n";
}
