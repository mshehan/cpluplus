/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: April 21st, 2015                            *
 * Title: project 5                                      *
 * class: CIS 279                                        *
 ********************************************************/

#include "CD.h"

CD::CD()
{
  title = '\0';
  author = '\0';
  quantity = 0;
  cost = 0.0;
}

CD::CD(std::string titl)
{
  title = titl;
  author = '\0';
  quantity = 0;
  cost = 0.0;
}

CD::CD(std::string titl, std::string auth, int quan, double cst)
{
  title = titl;
  author = auth;
  quantity = quan;
  cost = cst;
}

bool CD:: operator ==(const CD& obj) const // uses string comparison
{
  return title == obj.title;
}
bool CD::operator<(const CD& obj) const
{
  return title < obj.title;
}
bool CD::operator>(const CD& obj) const
{
  return title > obj.title;
}

std::ostream& operator <<(std::ostream& out, const CD& obj)
{
  out<< "title: " << obj.title << std::endl;
  out << "author: " << obj.author << std::endl;
  out << "quantity: " << obj.quantity << std::endl;
  out << "cost: " << obj.cost << "\n\n";
  
  return out;
}
