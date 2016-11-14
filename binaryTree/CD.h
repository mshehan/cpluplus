/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: April 21st, 2015                            *
 * Title: project 5                                      *
 * class: CIS 279                                        *
 ********************************************************/
#ifndef __Project_5__CD__
#define __Project_5__CD__

#include <string>
#include <iostream>


class CD
{
private:
  std::string title;  //CD’s title
  std::string author; // CD’s author
  int quantity;   //CD’s quantity in stock
  double cost;    // cost of one CD
    
public:
  CD();
  CD(std::string titl);
  CD(std::string titl,std::string auth,int quan,double cst);
  
  bool operator==(const CD& obj) const;   // two CD’s are equal if they have the same title
  bool operator<(const CD& obj) const;     // ordering is based on title (the string class natural ordering works here
  bool operator>(const CD& obj) const;
  
  friend std::ostream& operator<<(std::ostream& out,const CD& obj);

};

#endif /* defined(__Project_5__CD__) */
