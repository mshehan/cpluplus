/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: May 2, 2015                                 *
 * Title: project 6                                      *
 * class: CIS 279                                        *
 ********************************************************/
#ifndef __priorityQueue__Patient__
#define __priorityQueue__Patient__

#include <iostream>
#include <string>

using namespace std;

class Patient
{
private:
  string name;
  string malady;
  int thepriority;
    
public:
  Patient();
  Patient(string thename, string themal, int priority);
  
  string getName();
  string getMalady();
  int getPriority();
  
  const bool operator <(const Patient& obj);
  const bool operator >(const Patient& obj);
  const bool operator ==(const Patient& obj);
  
  friend ostream& operator<<(ostream& out,const Patient& obj);
    
};



#endif /* defined(__priorityQueue__Patient__) */
