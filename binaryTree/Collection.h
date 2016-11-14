/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: April 21st, 2015                            *
 * Title: project 5                                      *
 * class: CIS 279                                        *
 ********************************************************/

#ifndef Project_5_Header_h
#define Project_5_Header_h

#include "bintree.h"

template <class T>
class Collection:public binary_tree_node<T>
{
private:
  binary_tree_node<T>* root;
  
  void recPrint(binary_tree_node<T>* root) const;
//Effect:  prints the collection data using in order traversal
//Precondition:  None
//Postcondition: returns the number of values in the collection

public:
    
  Collection(){root = NULL;}
//Effect:  creates an empty Collection
//Postcondition:   the of this collection is empty    

  Collection(const Collection& obj);
// Effect:  copy constructor for this class
//Postcondition:  the new object is a unique copy of obj    

  void insert(const T& value);
//Effect:  this value has been added to the collection
//Postcondition:  the collection contains one more value 

  bool isThere(const T& value) const;
//Effect:  determines if this value is in the collection
//Returns: true if the value is in the Collection, otherwise returns false    

  void update(const T& value,  const T& newValue);
//Effect:  updates a value which exists in the collection
//Precondition:  this function assumes that ‘value’ exists in this collection
//Postcondition:  finds and replaces the data ‘value’  with ‘newValue’

  void operator=(const Collection& obj);
//Effect:  assignment overload for this class
//Precondition:  None
//Postcondition:  calling object is now unique and identical to obj

  void printTree() const;
//Effect:  prints out all data in this collection using ‘inorder’ traversal
//Precondition:  None
//Postcondition:  the collection is unchanged
  
  int size() const;
//Effect:  determines the number of values in the collection
//Precondition:  None
//Postcondition: returns the number of values in the collection


  ~Collection();
//Effect:   class destructor
//Postcondition:  leave this Collection object emtpy
    
  T getItem(const T& value);
    
};

template <class T>
Collection<T>::Collection(const Collection& obj)
{
  root = tree_copy(obj.root);
}

template <class T>
void Collection<T>::insert(const T& value)
{
  binary_tree_node<T>* cursor; // helps to search where to insert new value.
  
  bool done; // tells whether or not one has reached the bottom of the tree.
  
  if(root == NULL)// case: empty tree
  {
    root = new binary_tree_node<T>(value);
  }
  else if(root != NULL)
  {
    cursor = root;
    done = false;
    
    while(done == false)
    {
      if(value == cursor->data() || value < cursor->data())
      {
        if(cursor->left() == NULL)
        {
          cursor->set_left(new binary_tree_node<T>(value));
          done = true;
        }
        else
          cursor = cursor -> left();
      }
      
      else
      {
        if(cursor -> right() == NULL)
        {
          cursor->set_right(new binary_tree_node<T>(value));
          done = true;
        }
        else
            cursor = cursor->right();
        }
    }
  }

}
template <class T>
bool Collection<T>::isThere(const T& value) const
{
  binary_tree_node<T> *cursor = root;
  int isThere = 0;
  
  while(cursor != NULL)
  {
    if(value == cursor->data())
    {
      isThere++;
      cursor = cursor->left();
    }
    
    else if(value < cursor->data())
      cursor = cursor->left();
    
    else
      cursor = cursor->right();
  }
  return isThere;
}

template <class T>
void Collection<T>::update(const T& value, const T& newValue)
{
  binary_tree_node<T> *cursor = root;
  while(cursor != NULL)
  {
    if(value == cursor->data())
    {
      cursor->set_data(newValue);
      break; 
    }
    
    else if(value < cursor->data())
      cursor = cursor->left();
    
    else
      cursor = cursor->right();
  }
}

template <class T>
void Collection<T>::operator =(const Collection& obj)
{
  if(this != &obj)
  {
    tree_clear(root);
    root = tree_copy(obj.root);
  }
}

template <class T>
void Collection<T>::printTree() const
{
  recPrint(Collection::root);
}

template <class T>
int Collection<T>::size() const
{
  return tree_size(root);
}

template<class T>
Collection<T>::~Collection()
{
  tree_clear(root);
}

template <class T>
void Collection<T>::recPrint(binary_tree_node<T>* root) const
{
  if(root != NULL)
  {
    recPrint(root->left());
    std::cout << root->data() << std::endl;
    recPrint(root->right());
  }
}

template <class T>
T Collection<T>::getItem(const T& value)
{
  binary_tree_node<T> *cursor = root;
  
  while(cursor != NULL)
  {
    if(value == cursor->data())
    {
      return cursor -> data();
    }
    
    else if(value < cursor->data())
      cursor = cursor->left();
    
    else
      cursor = cursor->right();
  }
  
  return value;
}



#endif
