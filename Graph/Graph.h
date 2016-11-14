/*
 * Name: Matthew Shehan, Damon Chan                      *
 * Due Date: May 21, 2015                                *
 * Title: project 8                                      *
 * class: CIS 279                                        *
 */
/*
 This class is called Graph.
 vertexList[MAXIMUM];
 List<EdgeNode> edges[MAXIMUM];
 size_t many_vertices;
 
 Graph();
 
 void add_vertex(const Item& label);
 postcondition: the size of the graph has been increased by adding one new vertex. 
 this new vertex has the specified label and no edges
 
 void add_edge(size_t source, size_t target);
 Precondition:(source < size()) and (target < size())
 Postcondition: the graph has all the edges that it originally had,
 and it also has another edge from the specified source to 
 the specified target
 
 void remove_edge(size_t source, size_t target);
 precondition (source < size() && target < size())
 postcondition: the graph has all the edges that it originally had,
 and it also has another edge from the specified source to the
 specified target (if this edge was already present, then
 the graph is unchaged
 
 Item& operator[](size_t vertex);
 precondition: vertex < size()
 postcondition: the return value is a reference to the label
 of the specified vertex
 
 Item operator[](size_t vertex) const;
 precondition: vertex < size()
 postcondition: the return value is a reference of the label of
 the specified vertex
 NOTE; this function differs from the non-const version because
 its return value is simply a copy of the Item (rather than a reference
 of type Item&). Since this function returns only a copy of the Item,
 it is a const member function
 
 size_t size() const;
 postcondition:: return value is the number of verticies 
 in the graph
 
 bool is_edge(size_t source, size_t target) const;
 precondition: (source < size() && target < size()
 postcondition: the return value is a set that contains all the vertex
 numbers of vertices that are the target of an edge whose source
 is at the specified vertex
 
 set<size_t> neighbors(size_t vertex) const;
 Precondtion: vertex < size()
 postcondition: the return value is a set that contains all the vertex
 numbers of vertices that are the target of an edge whose source is at
 the specified vertex
 
 bool is_path(size_t source, size_t target);
 precondition: source < size() && target < size()
 postcondition: the return value is true if the graph has a path
 from source to target otherwise the return value is false
 */
#ifndef _Header_h
#define _Header_h
const size_t MAXIMUM = 100;
#include <list>
#include <set>
#include <cstdlib>
#include <stack>
#include <queue>
#include "EdgeNode.h"

template <class Item>
class Graph{
public:
  Graph();
  void add_vertex(const Item& label);
  void add_edge(size_t source, size_t target);
  void remove_edge(size_t source, size_t target);
  
  Item& operator[](size_t vertex);
  Item operator[](size_t vertex) const;
  size_t size() const;
  bool is_edge(size_t source, size_t target);
  
  std::set<size_t> neighbors(size_t vertex) ;
  bool is_path(size_t source, size_t target); 
private:
  Item vertexList[MAXIMUM];
  std::list<EdgeNode> edges[MAXIMUM];
  size_t many_vertices; // size of the vertex list    
    
};
template <class Item>
Graph<Item>::Graph() {
    many_vertices = 0;
}

template <class Item>
void Graph<Item>::add_vertex(const Item& label) {
  if(size() < MAXIMUM) {
    vertexList[many_vertices] = label;
    many_vertices++;
  }
}

template <class Item>
void Graph<Item>::add_edge(size_t source, size_t target) {
  if(source < size() && target < size()) {
      edges[source].push_back(EdgeNode(target));
  }
}

template <class Item>
void Graph<Item>::remove_edge(size_t source, size_t target) {
  if(source < size() && target < size()) {
      edges[source].remove(EdgeNode(target));
  }
}

template <class Item>
Item& Graph<Item>::operator[](size_t vertex) {
  return vertexList[vertex];
}

template <class Item>
Item Graph<Item>::operator[](size_t vertex) const {
  return vertexList[vertex];
}

template <class Item>
size_t Graph<Item>::size() const {
  return many_vertices;
}

template <class Item>
bool Graph<Item>::is_edge(size_t source, size_t target) {
  std::list<EdgeNode>::iterator it = edges[source].begin();
  while(it != edges[source].end()) {
    if(it->getvnum() == target) {
        return true;
    } 
    ++it;
  }
  return false;
}
template <class Item>
std::set<size_t> Graph<Item>::neighbors(size_t vertex) {
  std::set<size_t> returnValues;
 
  for(std::list<EdgeNode>::iterator it = edges[vertex].begin();
      it != edges[vertex].end();++it) {
      
    returnValues.insert(it->getvnum());
  }
  
  return returnValues;
}

template <class Item>
bool Graph<Item>::is_path(size_t source, size_t target) {
  bool marked[MAXIMUM];
  for(int i = 0; i < size(); i++)
    marked[i] = false;
  
  std::queue<size_t> line;
  std::set<size_t>::iterator it;
  std::set<size_t> myNeighbors;
  size_t vertex = source;
  line.push(source);
  do
  {
    vertex = line.front();
    line.pop();
    if(!marked[vertex])
    {
      myNeighbors = neighbors(vertex);
      marked[vertex] = true;
      if(vertex == target)
      {
          return true;
      }
      for(it = myNeighbors.begin();it != myNeighbors.end(); ++it)
        line.push(*it);
    }
  }while(!line.empty());
  return false;
}


/* template<class Item>
 bool Graph<Item>::is_path(size_t source, size_t target) // depth-first
 {
   bool marked[MAXIMUM];
   for(int i = 0; i < size(); i++)
      marked[i] = false;
   std::stack<size_t> jar;
   std::set<size_t>::iterator it;
   std::set<size_t> myNeighbors;
   
   size_t vertex = source;
   jar.push(vertex);
   do
   {
     vertex = jar.top();
     jar.pop();
     if(!marked[vertex])
     {
       myNeighbors = neighbors(vertex);
       marked[vertex] = true;
       if(vertex == target)
       {
         return true;
         break;
       }
   
       for(it = myNeighbors.begin();
       it != myNeighbors.end();++it)
         jar.push(*it);
     }
       
   }while(!jar.empty());
  
  return false;
 }
*/
#endif
