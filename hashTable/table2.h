/********************************************************
* Name: Matthew Shehan                                  *
* Due Date: May 12, 2015                                *
* Title: project 7                                      *
* class: CIS 279                                        *
 ********************************************************/
// FILE: table2.h
// TEMPLATE CLASS PROVIDED: Table<RecordType>
//   This class is a container template class for a Table of records.
//   The template parameter, RecordType, is the data type of the records in the
//   Table. It may contain any type with a default constructor, a copy constructor,
//   an assignment operator, and a public integer member variable called key.
//
// CONSTRUCTOR for the Table<RecordType> template class:
//   Table( )
//     Postcondition: The Table has been initialized as an empty Table.
//
// MODIFICATION MEMBER FUNCTIONS for the Table<RecordType> class:
//   void insert(const RecordType& entry)
//     Precondition: entry.key >= 0. Also if entry.key is not already a key in
//     the table, then the Table has space for another record
//     (i.e., size( ) < CAPACITY).
//     Postcondition: If the table already had a record with a key equal to
//     entry.key, then that record is replaced by entry. Otherwise, entry has
//     been added as a new record of the Table.
//
//   void remove(int key)
//     Postcondition: If a record was in the Table with the specified key, then
//     that record has been removed; otherwise the table is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the Table<RecordType> class:
//   bool is_present(const Item& target) const
//     Postcondition: The return value is true if there is a record in the
//     Table with the specified key. Otherwise, the return value is false.
//
//   void find(int key, bool& found, RecordType& result) const
//     Postcondition: If a record is in the Table with the specified key, then
//     found is true and result is set to a copy of the record with that key.
//     Otherwise found is false and the result contains garbage.
//
//   size_t size( ) const
//     Postcondition: Return value is the total number of records in the
//     Table.
//
// VALUE SEMANTICS for the Table<RecordType> template class:
//   Assignments and the copy constructor may be used with Table objects.
//
// DYNAMIC MEMORY USAGE by the Table<RecordType> template class:
//   If there is insufficient dynamic memory, then the following functions
//   can call new_handler: the copy constructor, insert, the assignment
//   operator.

#ifndef TABLE2_H
#define TABLE2_H
#include <cstdlib>    // Provides size_t
#include "node2.h"    // Provides the node type, from Figure 6.5 on page 306
#include <string>
const std::size_t TABLE_SIZE = 811;
template <class RecordType>
class table
{
public:
  // CONSTRUCTORS AND DESTRUCTOR
  table( );
  table(const table& source);
  ~table( );
  // MODIFICATION MEMBER FUNCTIONS
  void insert(const RecordType& entry);
  void remove(int key);
  void operator =(const table& source);
  // CONSTANT MEMBER FUNCTIONS
  void find(int key, bool& found, RecordType& result) const;
  bool is_present(int key) const;
  std::size_t size( ) const { return total_records; }
    
private:
  node<RecordType> *data[TABLE_SIZE];
  std::size_t total_records;
      
  // HELPER MEMBER FUNCTION
  std::size_t hash(int key) const ;
};



template <class RecordType>
table<RecordType>::table()
{
  total_records = 0;
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    data[i] = NULL;
  }
}

		  
template <class RecordType>
table<RecordType>::table(const table& source)
{
  total_records = source.total_records;
  
  node<RecordType> *tail;
  
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    list_copy(source.data[i],data[i], tail);
  }
    
}

template <class RecordType>
table<RecordType>::~table( )
{
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    list_clear(data[i]);
  }
}

// HASH FUNCTION #1
template <class RecordType>
std::size_t table<RecordType>::hash(int key) const
{
  std::string phone = std::to_string(key);
  std::string val_1 = phone.substr(0,2);
  std::string val_2 = phone.substr(2,2);
  
  int one = std::atoi(val_1.c_str());
  int two = std::atoi(val_2.c_str());
  
  return one+two; 
		 
}
// HASH FUNCTION #2
/*
 template<class RecordType>
 std::size_t table<RecordType>::hash(int key) const
{
    return key%TABLE_SIZE;
}*/

        
// MODIFICATION MEMBER FUNCTIONS
template <class RecordType>
void table<RecordType>::insert(const RecordType& entry)
{
  if(entry.key >= 0 && total_records < TABLE_SIZE)
  {
    std::size_t i = hash(entry.key);
    if(!is_present(entry.key))
    {
        
      list_head_insert(data[i], entry);
      total_records++;
    }
    else
    {
      remove(entry.key);
      insert(entry);
    }
  }
}

template <class RecordType>
void table<RecordType>::remove(int key)
{
  std::size_t i = hash(key);
  RecordType obj;
  node<RecordType>* ptr = data[i];
  node<RecordType>* previous = NULL;
  bool isThere;
  
  find(key,isThere, obj);
  
  if(isThere)
  {
    if(ptr->data().key == key)
    {
      list_head_remove(data[i]);
    }
    else
    {
      while(ptr->data().key != obj.key)
      {
        previous = ptr;
        ptr = ptr->link();
      }
      
      list_remove(previous);
    }
  }
}


template <class RecordType>
void table<RecordType>::operator =(const table& source)
{
  if(this != &source)
  {
    node<RecordType>* tail;
    total_records = source.total_records;
    for(int i = 0; i < total_records; i++)
    {
      list_clear(data[i]);
      list_copy(source.data[i],data[i],tail);
    }
  }
    
}

    // CONSTANT MEMBER FUNCTIONS
template <class RecordType>
void table<RecordType>::find(int key, bool& found, RecordType& result) const
{
  found = false;
  size_t i = hash(key);
  node<RecordType>* ptr;
  ptr = data[i];
  if(ptr != NULL)
  {
    if(ptr->data().key == key)
    {
      result = ptr->data();
      found = true;
      return;
    }
    else
      while(ptr != NULL)
        ptr = ptr->link();
  }
}
 
template <class RecordType>
bool table<RecordType>::is_present(int key) const
{
  size_t i = hash(key);
  node<RecordType>* ptr;
  ptr = data[i];
  
  while(ptr != NULL)
  {
    if(ptr->data().key == key)
    {
      return true;
      break;
    }
    else
      while(ptr != NULL)
        ptr = ptr->link();
          
  }
  return false;
}


#endif
