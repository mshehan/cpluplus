/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: February 10, 2015                           *
 * Title: project 4 (GStack, StringEditor Class)         *
 * class: CIS 279                                        *
 ********************************************************/

#ifndef __GStack__StringEditor__
#define __GStack__StringEditor__

#include "GStack.h"


class StringEditor
{
public:
    //constructors for the StringEditor class
    StringEditor();
    StringEditor(string left, string right);
    bool isCursoratfront();//if cursor is at front returns true else false
    bool isCursoratend();//if cursor is at end returns true else false
    void insertChar(char c); //inserts char at position preceding the cursor
    void deleteChar(); //deletes char to right of the cursor
    void backspace(); //deletes char to left of the cursor
    void frontOfString(); //moves cursor to the front
    void endOfString(); //moves cursor to the end
    void moveCursorLeft(); //moves cursor over one to left
    void moveCursorRight(); //moves cursor over one to right
    
    friend ostream& operator <<(ostream& out, const StringEditor& obj);
    // prints StringEditor obj to screen
private:
    GStack<char> leftChar;
    GStack<char> rightChar;
};
#endif /* defined(__GStack__StringEditor__) */
