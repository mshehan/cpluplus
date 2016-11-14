/*
 * Name: Matthew Shehan, Damon Chan                      *
 * Due Date: May 21, 2015                                *
 */

#include "EdgeNode.h"
EdgeNode::EdgeNode() {
    vertex_num = 0;
}

EdgeNode::EdgeNode(int vnum) {
    vertex_num = vnum;
}

void EdgeNode:: setvnum(int vnum) {
    vertex_num = vnum;
}
int EdgeNode::getvnum() {
    return vertex_num;
}
bool EdgeNode::operator==(const EdgeNode& obj) const {
    return obj.vertex_num == vertex_num;
}
