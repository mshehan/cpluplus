#ifndef TEST_CLASS_H
#define TEST_CLASS_H


#include <iostream>
using namespace std;


template <class T>
class List
{
private:
  T* data; // dynamic array which stores list data
  int size;// capacity of list
  int howmany;// number of values in the list
public:
  List();// creates list with capacity of 10
  List(int max);// creates a list with capacity of max
  bool isFull() const;// returns true if this list is full
  bool isEmpty() const;// returns true if this list is empty
  void insert(const T& value);
  //if list is not full, insert adds this item to the list
  //otherwise a list exception is thrown
  
  T last() const; // returns the last item in the list
  // if the list is empty an exception is thrown
  
  int occurs(const T& value) const; 
  // returns the number of times 'value' occurs in the list
  void deleteAll(const T& value); // deletes all occurances of 'value'
  bool operator ==(const List<T>& operand) const; 
  // returns true if this object is equal to operand
  T& operator[](const int index);
  friend ostream& operator<< (ostream& out, const List& robject);
};

template <class T>
List<T>::List() {
  data = new T[size = 10];
  for(int i = 0; i < size; i++) {
    data[i] = 0;
  }
}
template <class T>
List<T>::List(int max) {
  data = new int[size = max];
  for(int i = 0; i < size; i++) {
    data[i] = 0;
  }
}

template <class T>
bool List<T>::isFull()const {
  return (howmany == size);
}

template <class T>
bool List<T>:: isEmpty() const {
   return (howmany == 0);
}

template <class T>
void List<T>::insert(const T& value) {
  if (isFull())
    throw value;
  
  data[howmany] = value;
  howmany++
  
  catch (int value) {
      cout << "your list is full " << value << " was not inserted";
  }
}
template <class T>
T List<T>::last() const {
  return data[howmany-1];
}

template <class T>
int List<T>::occurs(const T& value) const // OCCURS
{
    int occurs = 0;
    for( int i = 0; i < size; i++) {
      if( data[i] == value) {
          occurs++;
      }
    }
    return occurs;
}

template <class T>
void List<T>::deleteAll(const T& value) {
  for( int i = 0; i < size; i++) {
    if( data[i] == value) {
        data[i] = 0;
    }
  }
}

template <class T>
bool List<T>::operator==(const List& operand) const
{
    for( int i = 0; i < size; i ++)
    {
        if (operand.data[i] != data[i])
        {
            return false;
            break;
        }
    }
    
    return true;
    
}

template <class T>
T& List<T>::operator[](const int index)
{
    return data[index]; 
}

#endif //TEST_CLASS_H
