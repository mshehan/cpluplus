/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: February 5, 2015                            *
 * Title: project 2 (Bag/MoneyBag Class)                 *
 * class: CIS 279                                        *
 ********************************************************/
#ifndef __project2__MoneyBag__
#define __project2__MoneyBag__


#include "bag.h"



class MoneyBag: public bag
{
public:
  
  MoneyBag();
  //creates an empty MoneyBag object
  
  void insert(bag::size_type howmany, int denom);
  //precondition: howmany > 0, and denom must be 1,5,10,or 20
  //postcondition: object now contains howmany more bills
  //effect: insert a number of bills of the same denom
  
  long totalAll() const;
  //precondition: none
  //postcondition: object is unchanged
  // effect computes the total amount of cash in the MoneyBag
  
  long total(int denom) const;
  //precondition: none
  //postcondition: object is unchaged
  // computes the total of all one demonination
  
  int largest() const;
  //preconditon: bag is not empty
  //postcondition: object is unchanged
  // returns the largest denomination which exists in the MoneyBag
  // effect: determines the largest bill which exists in the MoneyBag

};
#endif /* defined(__project2__MoneyBag__) */
