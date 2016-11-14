/**********************************
* Name: Matthew Shehan            *
* Due Date: May 12, 2015          *
* Title: project 7                *
* class: CIS 279                  *
 **********************************/
#include "Customer.h"

Customer::Customer()
{
  name = std::string();
  address = std::string();
  key = int();
}
Customer::Customer(string cName, string cAddress, int cPhone)
{
  name = cName;
  address = cAddress;
  key = cPhone;
}

void Customer::set_name(string new_name)
{
  name = new_name;
}
void Customer::set_address(string new_address)
{
  address = new_address;
}
void Customer::set_key(int new_phone)
{
  key = new_phone;
}

string Customer::get_name()
{
  return name;
}
string Customer::get_address()
{
  return address;
}
int Customer::get_key()
{
  return key;
}
void Customer::operator=(const Customer& source)
{
  if(this!= &source)
  {
    key = source.key;
    address = source.address;
    name = source.name;
  }
}
bool Customer::operator==(const Customer& obj) const
{
  return key == obj.key; 
}

ostream& operator<<(ostream& out, const Customer& obj)
{
  out << "----------------------------\n";
  out << "name: " << obj.name << "\n";
  out << "address: " << obj.address << "\n";
  out << "phone: " << obj.key << "\n";
  out << "-----------------------------\n\n";
  
  return out;
}
