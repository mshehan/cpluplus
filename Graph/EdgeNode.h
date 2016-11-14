/*
 * Name: Matthew Shehan, Damon Chan                      *
 * Due Date: May 21, 2015                                *
 */
#ifndef __Graph__EdgeNode__
#define __Graph__EdgeNode__
class EdgeNode
{
private:
  int vertex_num;
public:
  EdgeNode();
  EdgeNode(int vnum);
  void setvnum(int vnum);
  int getvnum();
  bool operator ==(const EdgeNode& obj)const;
};
#endif /* defined(__Graph__EdgeNode__) */
