/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: February 10, 2015                           *
 * Title: project 4 (GStack, StringEditor Class)         *
 * class: CIS 279                                        *
 ********************************************************/
#include "StringEditor.h"

StringEditor::StringEditor()
{
    leftChar.push(NULL);
    rightChar.push(NULL);
}

StringEditor::StringEditor(string left, string right):StringEditor() {
  for(size_t i = 0; i < left.length(); i++)
      leftChar.push(left[i]);
  for(int i = right.length()-1; i >= 0; i--) {
    try {
      rightChar.push(right[i]);
    }
    catch(StackException& e) {
      cout << e.what() << e.fullStack();
    }
  }
}

bool StringEditor::isCursoratfront() {
  return leftChar.isEmpty();
}

bool StringEditor::isCursoratend() {
  return rightChar.isEmpty();
}

void StringEditor::insertChar(char c) {
  try {
    leftChar.push(c);
  }
  catch(StackException& e) {
    cout << e.what() << e.fullStack();
  }
}

void StringEditor::deleteChar() {
  if(!isCursoratend()) {
    try {
      rightChar.pop();
    }
    catch(StackException& e) {
      cout << e.what() << e.emptyStack();
    }
  }
}
void StringEditor::backspace() {
  if(!isCursoratfront()) {
    try {
      leftChar.pop();
    }
    catch(StackException& e){
      cout << e.what() << e.emptyStack();
    }
  }
}

void StringEditor::frontOfString(){
  char copy; // holds the char popped from left
  while(!leftChar.isEmpty()) {
    try {
      leftChar.pop(copy);
    }
    catch(StackException& e) {
      cout << e.what() << e.emptyStack();
    }
    rightChar.push(copy); // pushes the value of copy into rightChar
  }
}

void StringEditor::endOfString() {
  char copy; // holds the char popped from left
  while(!rightChar.isEmpty()) {
    try {
        rightChar.pop(copy);
    }
    catch(StackException& e) {
        cout << e.emptyStack();
    }
    leftChar.push(copy); // pushes the value of copy into rightChar
  }
}

void StringEditor::moveCursorLeft() {
  if(!isCursoratfront()) {
    char copy;
    leftChar.pop(copy);
    rightChar.push(copy);
  }
}
void StringEditor::moveCursorRight() {
  char copy;
  if(!isCursoratend()) {
    rightChar.pop(copy);
    leftChar.push(copy);
  }
}

ostream& operator <<(ostream& out, const StringEditor& obj)
{
  StringEditor copy(obj); // creates a copy of the parameter
  GStack<char> printLeft; // stack to be printed to screen
  char print; // stores that character printed to the screen
  
  while (!copy.leftChar.isEmpty()) // moves everything into printed stack
  {
    copy.leftChar.pop(print);
    printLeft.push(print);
  }
  // prints left side
  while (!printLeft.isEmpty()) {
    printLeft.pop(print);
    cout << print;
  }
  out << "^"; //used as a cursor

  //prints the right side
  while(!copy.rightChar.isEmpty()) {
    copy.rightChar.pop(print);
    out << print;
  }
  return out;
}

