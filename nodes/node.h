/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: February 10, 2015                           *
 * Title: project 3 (Nodes, StringEditor Class)          *
 * class: CIS 279                                        *
 ********************************************************/
// TYPEDEF for the node class:
//     Each node of the list contains a piece of data and a pointer to the
//     next node. The type of the data is defined as node::value_type in a
//     typedef statement. The value_type may be any
//     of the built-in C++ classes (int, char, ...) or a class with a copy
//     constructor, an assignment operator, and a test for equality (x == y).
//
// NOTE:
//   Some of the functions have a return value which is a pointer to a node.
//   Each of these  functions comes in two versions: a non-const version (where
//   the return value is node*) and a const version (where the return value
//   is const node*). 
// EXAMPLES:
//    const node *c;
//    c->link( ) activates the const version of link
//    list_search(c,... calls the const version of list_search
//    node *p;
//    p->link( ) activates the non-const version of link
//    list_search(p,... calls the non-const version of list_search
//
// DYNAMIC MEMORY usage by the toolkit: 
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: the constructor, list_head_insert, list_insert, list_copy,
//   list_piece.


#include <cstdlib> // Provides size_t and NULL
#include <cassert>    // Provides assert
#include <iostream>

class node
{
public:
	
  typedef char value_type;
    
// CONSTRUCTOR
  node(const value_type& init_data = value_type( ),node* init_link = NULL)
  {
    data_field = init_data;
    link_field = init_link;
  }

// Member functions to set the data and link fields:

/***********************************************************
void set_data(const value_type& new_data)
Postcondition: The node now contains the specified new data.
***********************************************************/
  void set_data(const value_type& new_data)
  {
    data_field = new_data;
  }
/***********************************************************
void set_link(node* new_link)
Postcondition: The node now contains the specified new link.
***********************************************************/
  void set_link(node* new_link)
  {
    link_field = new_link;
  }

// Constant member function to retrieve the current data:
        
/**********************************************************
 value_type data( ) const
 Postcondition: The return value is the data from this node.
***********************************************************/
  value_type data( ) const
  {
    return data_field;
  }

// Two slightly different member functions to retreive
// the current link:
    
/******************************************
 both of these functions get the link_field
 ******************************************/
  const node* link( ) const
  {
    return link_field;
  }
  
  node* link( )
  {
    return link_field;
  }

  private:

  value_type data_field; //stores the data in the linked list
  
  node* link_field; //acts as the pointer to each item in the list

};

// FUNCTIONS for the linked list toolkit
/*************************************************************************
size_t list_length(const node* head_ptr)
Precondition: head_ptr is the head pointer of a linked list.
Postcondition: The value returned is the number of nodes in the linkedlist.
*************************************************************************/
std::size_t list_length(const node* head_ptr);

/*********************************************************************
void list_head_insert(node*& head_ptr, const node::value_type& entry)
Precondition: head_ptr is the head pointer of a linked list.
Postcondition: A new node containing the given entry has been added at
the head of the linked list; head_ptr now points to the head of the new,
longer linked list.
**********************************************************************/
void list_head_insert(node*& head_ptr, const node::value_type& entry);

/********************************************************************
void list_insert(node* previous_ptr, const node::value_type& entry)
Precondition: previous_ptr points to a node in a linked list.
Postcondition: A new node containing the given entry has been added
after the node that previous_ptr points to.
*******************************************************************/
void list_insert(node* previous_ptr, const node::value_type& entry);

/****************************************************************************
 const node* list_search(const node* head_ptr, const node::value_type& target)
 node* list_search(node* head_ptr, const node::value_type& target)
 Precondition: head_ptr is the head pointer of a linked list.
 Postcondition: The pointer returned points to the first node containing
 the specified target in its data member. If there is no such node, the
 null pointer is returned.
 ****************************************************************************/
node* list_search(node* head_ptr, const node::value_type& target);

const node* list_search(const node* head_ptr, 
    const node::value_type& target);

/****************************************************************************
const node* list_locate(const node* head_ptr, size_t position)
node* list_locate(node* head_ptr, size_t position)

Precondition: head_ptr is the head pointer of a linked list, and position > 0.
Postcondition: The pointer returned points to the node at the specified
position in the list. (The head node is position 1, the next node is
position 2, and so on). If there is no such position, then the null
pointer is returned.
***************************************************************************/
node* list_locate(node* head_ptr, std::size_t position);

const node* list_locate(const node* head_ptr, std::size_t position);

/******************************************************************
void list_head_remove(node*& head_ptr)
Precondition: head_ptr is the head pointer of a linked list, with at
least one node.
Postcondition: The head node has been removed and returned to the heap;
head_ptr is now the head pointer of the new, shorter linked list.
*******************************************************************/
void list_head_remove(node*& head_ptr);

/*********************************************************************
void list_remove(node* previous_ptr)
Precondition: previous_ptr points to a node in a linked list, and this
is not the tail node of the list.
Postcondition: The node after previous_ptr has been removed from the
linked list.
*********************************************************************/
void list_remove(node* previous_ptr);

/*******************************************************************
void list_clear(node*& head_ptr)
Precondition: head_ptr is the head pointer of a linked list.
Postcondition: All nodes of the list have been returned to the heap,
and the head_ptr is now NULL.
*******************************************************************/
void list_clear(node*& head_ptr);

/***********************************************************************
 void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
Precondition: source_ptr is the head pointer of a linked list.
Postcondition: head_ptr and tail_ptr are the head and tail pointers for
a new list that contains the same items as the list pointed to by
source_ptr. The original list is unaltered.
************************************************************************/
void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);


/**************************************************************************
 Precondition: headptr is the head pointer of a linked list, with at least one
 node.
 Postcondition: The tail (last) node has been removed and returned to the heap
 head_ptr is the head pointer of the new, shorter linked list.
******************************************************************************/
void list_tail_remove(node*& headptr);

/***********************************************************************
Precondition: headptr is the head pointer of a linked list.
Postcondition: A new node containing the given entry has been added at
the tail of the linked list; head_ptr points to the head of the new,longer 
linked list.
************************************************************************/
void list_tail_insert(node*& headptr, const node::value_type& entry);

/*************************************************************************
 Precondition: headptr is the head pointer of a linked list with at least
 one node
 Postcondition: the list is unchanged
 Returns: a pointer to the last node in the list
 **************************************************************************/
node* getLast(node* headptr);

/***************************************************************************
 Precondition:   headptr is the head pointer of a linked list  (list may be
 empty)
 Postcondition:  the list elements are printed to screen
****************************************************************************/
void outList(node* headPtr);



