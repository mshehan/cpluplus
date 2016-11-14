/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: February 10, 2015                           *
 * Title: project 4 (GStack, StringEditor Class)         *
 * class: CIS 279                                        *
 ********************************************************/
#ifndef GStack_Header_h
#define GStack_Header_h
#include <cstdlib>
#include <list>
#include <exception>

using namespace std;
class StackException:public exception {
public:
  const char* emptyStack() {
    return "your stack is empty.\n";
  }
  const char* fullStack() {
    return "your stack is full.\n";
  }
  const char* what() {
    return "Stack Exception: ";
  }
};
template <class T>
class GStack
{
private:
  list<T> Stack;
  T stackTop;
public:
  GStack();
  bool isEmpty() const;
  void push(const T& newItem);
  void pop();
  void pop(T& stackTop);
  void getTop(T& stackTop) const;

};
/***class definitions***/
template <class T>
GStack<T>::GStack(){
  Stack; 
  stackTop = stack.front();
}
template <class T>
bool GStack<T>::isEmpty() const {
    return stack.empty();
}

template <class T>
void GStack<T>::push(const T& newItem) {
  if(stack.size() == stack.max_size())
    throw StackException();
    
  stack.push_front(newItem);
}
template <class T>
void GStack<T>::pop() {
  if(isEmpty())
    throw StackException();
    
  stack.pop_front();
}
template <class T>
void GStack<T>::pop(T& stackTop) {
  if(isEmpty())
    throw StackException();
  
  stackTop = stack.front();
  stack.pop_front();  
}
template <class T>
void GStack<T>::getTop(T& stackTop) const {
  if(isEmpty())
    throw StackException();
  
  stackTop = stack.front();
}
#endif/* defined(__GStack__) */




