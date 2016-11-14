/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: February 10, 2015                           *
 * Title: project 3 (Nodes, StringEditor Class)          *
 * class: CIS 279                                        *
 ********************************************************/
#ifndef __nodes__StringEditor__
#define __nodes__StringEditor__

#include "node.h"
#include <string>


using namespace std;

class StringEditor
{
public:
 
// constructors
    StringEditor(){rightChar = NULL; leftChar = NULL;};     
    StringEditor(string left, string right);
    
/*********************************************************
 returns true or false depending on location of the cursor.
 *********************************************************/
    bool isCursoratfront();
    bool isCursoratend();

/*****************************************************************
the following functions insert or delete characters in the string
*****************************************************************/
    void insertChar(char c); // inserts char prior to cursor
    void deleteChar(); // deletes char following cursor
    void backspace(); // deletes char prior to cursor
    
/****************************************************************
the following fuctions manipulate the location of the cursor
moving the cursor to the front, end, left or right, respectively.
***************************************************************/
    
    void frontOfString();
    void endOfString();
    void moveCursorLeft();
    void moveCursorRight();
    
    friend ostream& operator <<(ostream& out, const StringEditor& obj);

private:
    
    node* rightChar; // stores characters to the right of the cursor
    node* leftChar; // stores characters to the left of the cursor
    
    
};

#endif /* defined(__nodes__StringEditor__) */

