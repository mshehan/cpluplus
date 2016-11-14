/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: May 2, 2015                                 *
 * Title: project 6                                      *
 * class: CIS 279                                        *
 ********************************************************/
#include "Patient.h"

Patient::Patient()
{
  name = string();
  malady = string();
  thepriority = int();
}

Patient::Patient(string thename, string themal, int priority)
{
  name = thename;
  malady = themal;
  thepriority = priority;
}

string Patient::getName()
{
  return name;
}
string Patient::getMalady()
{
  return malady;
}
int Patient::getPriority()
{
  return thepriority;
}

const bool Patient::operator <(const Patient& obj)
{
  return thepriority < obj.thepriority;
}
const bool Patient::operator >(const Patient& obj)
{
  return thepriority > obj.thepriority;
}
const bool Patient::operator ==(const Patient& obj)
{
  return thepriority == obj.thepriority;
}

ostream& operator<<(ostream& out,const Patient& obj)
{
  out << "-------------------------------\n";
  out << "name: " << obj.name << "\n";
  out << "malady: " << obj.malady << "\n";
  out << "priority: " << obj.thepriority << "\n";
  out << "-------------------------------\n\n";
  return out;
}
