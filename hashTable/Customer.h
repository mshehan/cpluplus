/**********************************************
 
 * Name: Matthew Shehan                                  *
 * Due Date: May 12, 2015                                *
 * Title: project 7                                      *
 * class: CIS 279                                        *
 
 This is the customer class.
 It stores information about each customer
 like their address, phone number, and name.
 
 this class uses a the default constructor
 and contains a constructor that take parameters
 for name, address and phone number.
 
 there are get and set functions
 for each piece of data in the class
 
 the '<<' operator is overloaded
 as well as the '=' operator
 to print a Customer object to the screen
 
 **********************************************/
#ifndef __hashTable__Customer__
#define __hashTable__Customer__

#include <iostream>
#include <string>
using namespace std;

class Customer
{
private:
  string name;
  string address;
public:
  int key;
  
  
  Customer();
  Customer(int cPhone);
  Customer(string cName, string cAddress, int cPhone);
  
  void set_name(string new_name);
  void set_address(string new_address);
  void set_key(int new_phone);
  
  string get_name();
  string get_address();
  int get_key();
  
  void operator =(const Customer& source);
  bool operator==(const Customer& obj) const;
  
  
  
  friend ostream& operator <<(ostream& out, const Customer& obj);
};


#endif /* defined(__hashTable__Customer__) */
