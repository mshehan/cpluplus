/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: February 10, 2015                           *
 * Title: project 3 (Nodes, StringEditor Class)          *
 * class: CIS 279                                        *
 ********************************************************/

#include "StringEditor.h"

//Default constructor inline

StringEditor::StringEditor(string left, string right):StringEditor()
{
    
  for(size_t i = 0; i < left.length(); i++)
  {
    char add = left[i];
    list_tail_insert(leftChar, add);
  }
  
  
  for(size_t i = 0; i < right.length(); i++)
  {
    char add = right[i];
    list_tail_insert(rightChar, add);
  }
    
    
}

bool StringEditor::isCursoratfront()
{
  return (leftChar == NULL);
}

bool StringEditor::isCursoratend()
{
    return (rightChar == NULL);
}

void StringEditor::insertChar(char c)
{
  list_tail_insert(leftChar,c);
}

void StringEditor::deleteChar() 
{
  if(!isCursoratend())
    list_head_remove(rightChar);
}

void StringEditor::backspace()
{
  if(!isCursoratfront())
    list_tail_remove(leftChar);
}

void StringEditor::frontOfString()
{
  if(!isCursoratfront())
  {
    node* temp_head;
    node* temp_tail;
  
    list_copy(leftChar,temp_head,temp_tail);
  
    temp_tail->set_link(rightChar);
    rightChar = temp_head;

    list_clear(leftChar);
  }
  
  else // if cursor is already at front
    return;
}

void StringEditor::endOfString()
{
  node* temp_head;
  node* temp_tail;
  
  if(isCursoratfront()) // handles case that leftChar is empty
  {
    list_copy(rightChar,temp_head,temp_tail);
    
    leftChar = temp_head;
    
    list_clear(rightChar);
  }
  
  else if(!isCursoratend()) // handles case that cursor is not at end
  {
    list_copy(rightChar,temp_head, temp_tail);

    temp_tail = getLast(leftChar);
    temp_tail -> set_link(temp_head);

    list_clear(rightChar);
  }
  
  else // handles case that cursor is at end
    return;
}

void StringEditor::moveCursorLeft()
{
 if(!isCursoratfront())
 {
   node* temp_prev;
   node* temp_tail;

   temp_prev = list_locate(leftChar, (list_length(leftChar) - 1));
   temp_tail = getLast(leftChar);

   temp_prev -> set_link(NULL);
   temp_tail -> set_link(rightChar);

   rightChar = temp_tail;
 }
 else
     return;
}

void StringEditor::moveCursorRight()
{
  node* temp_tail;
  node* new_tail;
  
  if(!isCursoratend())
  {
    temp_tail = getLast(leftChar);
    temp_tail -> set_link(rightChar);
    rightChar = rightChar -> link();
    new_tail = temp_tail -> link();
    new_tail -> set_link(NULL);
  }
  else
    return;
}

ostream& operator <<(ostream& out, const StringEditor& obj)
{
  outList(obj.leftChar);
  
  out << "^";
  
  outList(obj.rightChar);
  
  return out;
}
