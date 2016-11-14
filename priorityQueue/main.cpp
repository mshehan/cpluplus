/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: May 2, 2015                                 *
 * Title: project 6                                      *
 * class: CIS 279                                        *
 ********************************************************/
#include <iostream>
#include "Heap.h"
#include "Patient.h"
using namespace std;
int main() {
  
  string name;
  string malady;
  int priority;
  
  Heap<Patient> or1(2);
  Heap<Patient> or2(2);
  
  while(!or1.IsFull() || !or2.IsFull())
  {
    cout << "What is the Patient's name?\n";
    getline(cin, name);
    
    
    cout << "That's awesome, now what is the Patient's malady?\n";
    
    getline(cin,malady);
    
    
    cout <<"Wow, that sounds bad! so, what the Patient's Priority?\n";
    cin >> priority;
    cin.ignore();
    cout << "\n";
    
    cout << "ok, added a new patient to the OR\n";
    
    Patient thePatient(name,malady,priority);
    
    if(!or1.IsFull())
    {
      or1.add(thePatient);
    }
    else
    {
      or2.add(thePatient);
    }
    
  }
  
  cout << "woah, looks like all the Operating rooms are full\n\n";
  
  cout << "here are the patients in queue for OR1\n";
  cout << "--------------------------------------\n";
  while(!or1.IsEmpty())
  {
    Patient print;
    or1.remove(print);
    cout << print;
  }
  
  cout << "here are the patients in queue for OR2\n";
  cout << "---------------------------------------\n";
  while(!or2.IsEmpty())
  {
    Patient print;
    or2.remove(print);
    cout << print;
  }
}
