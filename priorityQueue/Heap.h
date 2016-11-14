/********************************************************
 * Name: Matthew Shehan                                  *
 * Due Date: May 2, 2015                                 *
 * Title: project 6                                      *
 * class: CIS 279                                        *
 ********************************************************/

class FullPQ{};
class EmptyPQ{};


// Definition of class Heap

template<class T>
class Heap
{
public:
  Heap(int);          // parameterized class constructor
  ~Heap();            // class destructor
  
  Heap( const Heap<T>& obj);  // copy constructor for this class

  Heap<T>& operator=(const Heap<T>& obj); // assignment overload
 
  bool IsEmpty() const;
  // Function: Determines whether the heap is empty.
  // Post: Function value = (heap is empty)
  
  bool IsFull() const;
  // Function: Determines whether the heap is full.
  // Post: Function value = (heap is full)
  
  void add(T newItem);
  // Function: Adds newItem to this heap
  // Post: if (the heap is full) exception FullPQ is thrown;
  //       else newItem is in the heap.
  
  void remove(T& item);
  // Function: Removes the root from this heap
  // and returns it in item.
  // Post: If (the priority heap is empty) exception EmptyPQ is thrown;
  //       else highest priority element has been removed from heap.
  //       item is a copy of removed element.


private:
  int length;     //number of values in this heap
  T* items;      // dynamic array to store heap data
  int maxItems;  //capacity of this heap
    
  int parent(int index);
  //precondition: none
  //postcondition: returns the index of the parent of the original index
  void moveUp(int index);
  //precondition: there are items in the array items[]
  //postcondition: switches the value of two items in an array
  int greatestChild(int index);
  //precondition: the index < length
  //postcondition: returns index of greatest child
  void moveDown(int index);
};

template<class T>
Heap<T>::Heap(int max)
{
  maxItems = max;
  items = new T[max];
  length = 0;
}


template<class T>
Heap<T>::~Heap()
{
  delete [] items;
}


template<class T>
Heap<T>::Heap(const Heap<T>& obj)
{
  length = obj.length;
  maxItems = obj.maxItems;
  delete [] items;
  items = new T[maxItems];
  for(int index = 0; index < maxItems; index++)
  {
    items[index] = obj.items[index];
  }
}

template<class T>
Heap<T>& Heap<T>::operator=(const Heap<T>& obj)
{
  if(this != &obj)
  {
    length = obj.length;
    maxItems = obj.maxItems;
    
    delete []items;
    items = new T[maxItems];
    
    for(int index = 0; index < length; index++)
    {
      items[index] = obj.items[index];
    }
  }
}

template <class T>
int Heap<T>::parent(int index)
{
  if(index <= 0)
  {
    return 0;
  }
  else
  {
    return (index-1)/2;
  }
}
template <class T>
int Heap<T>::greatestChild(int index)
{
  int lchild = (2*index)+1;
  int rchild = (2*index)+1;
  if((items[lchild] < items[rchild]) || (items[lchild] == items[rchild]))
  {
    return rchild;
  }
  else
  {
    return lchild;
  }
}

template <class T>
void Heap<T>::moveUp(int index)
{
  T temp = items[parent(index)];
  items[parent(index)] = items[index];
  items[index] = temp;
}
template <class T>
void Heap<T>:: moveDown(int index)
{
  T temp = items[index];
  items[index] = items[greatestChild(index)];
  items[greatestChild(index)] = temp;
}
template<class T>
void Heap<T>::remove (T& item)
// Post: element with highest priority has been removed 
//       from the heap; a copy is returned in item.
{
  if(IsEmpty())
  {
      throw EmptyPQ();
  }
  else
  {
    int indexer = 0;
    item = items[indexer];
    
    items[indexer] = items[length-1];
    
    
    length --;

    while((length < greatestChild(indexer)) 
        && (items[indexer] < items[greatestChild(indexer)]))
    {
      moveDown(indexer);
      indexer = greatestChild(indexer);
    }
  }
}
template<class T>
void Heap<T>::add(T newItem)
// Post: newItem is in the heap.
{
  if(IsEmpty())
  {
    items[0] = newItem;
    length++;
  }
  else if(!IsEmpty() && !IsFull())
  {
    int indexer = length; // used to hold indeces in the heap
    
    items[indexer] = newItem;
    while(items[parent(indexer)] < items[indexer])
    {
        moveUp(indexer);
        indexer = parent(indexer);
    }
    
    length++;
  }
  else
  {
    throw FullPQ();
  }
}


template<class T>
bool Heap<T>::IsFull() const
{
// Post: Returns true if the heap is full; false, otherwise.
  return length == maxItems;
}

template<class T>
bool Heap<T>::IsEmpty() const
{
// Post: Returns true if the heap is empty; false, otherwise.
  return length == 0;
}

