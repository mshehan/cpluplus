/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: February 5, 2015                            *
 * Title: project 2 (Bag/MoneyBag Class)                 *
 * class: CIS 279                                        *
 ********************************************************/
#include "MoneyBag.h"
#include <cassert>

MoneyBag::MoneyBag():bag()
{
    
}


void MoneyBag::insert(bag::size_type howmany, int denom)
{
  for(int i = 0; i < howmany; i++)
  {
      bag::insert(denom);
  }
}

long MoneyBag::totalAll() const
{
  long total = 0;
  
  for(int i = 0; i < bag::size(); i++)
  {
    total+= bag::getItem(i+1);
  }
  
  return total;
}

long MoneyBag::total(int denom) const
{
  long total = 0;
  
  for( int i = 0; i < bag::size(); i++)
  {
    if(bag::getItem(i+1) == denom)
    {
      total+= bag::getItem(i+1);
    }
  }
  
  return total;
}

int MoneyBag::largest() const
{
  int largest = 0;
  
  for(int i = 0; i < bag::size(); i++)
  {
    if(bag::getItem(i+1) > 0 && bag::getItem(i+1) > largest)
    {
      largest = bag::getItem(i+1);
    }
  }
  
  return largest;
}
