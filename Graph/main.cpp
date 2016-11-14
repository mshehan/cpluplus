/*
 * Name: Matthew Shehan, Damon Chan                      *
 * Due Date: May 21, 2015                                *
 * Title: project 8                                      *
 * class: CIS 279                                        *
*/
#include <iostream>
#include "Graph.h"
#include "EdgeNode.h"
#include <string>
#include <set>

void PrintMenu();
int main () {
  std::string course;
  std::string prereq;
  std::size_t courseNum, prereqNum;
  Graph<std::string> CourseGraph;
  int choice;
  std::cout << "Select a task from the list:\n";
  do
  {
    // Loop to repeat menu or exit
    PrintMenu();
    std::cin >> choice;
    
    std::cin.ignore (50,'\n');
        
    switch (choice)
    {
      //enter a new course        
      case 1: {
        std::cout <<"Enter a new course\n" << std::endl;
        std::getline (std::cin, course);
          if (CourseGraph.size() < MAXIMUM) {
            CourseGraph.add_vertex(course);
            std::cout <<"Course " <<CourseGraph[CourseGraph.size()-1] 
              <<" has been added\n";
            std::cout <<"The course number is " 
              <<CourseGraph.size()-1 << "\n";
          }
          else
            std::cout <<"The Course list is full\n";
        break;
      }
      
      // Enter a prerequisite relationship
      case 2: {
        std::cout 
          <<"Enter the course number to be assigned a prerequisite\n" 
          << "\n";
        std::cin >> courseNum;
        std::cout << "Enter the prerequisite course number\n" << "\n";
        std::cin >> prereqNum;
            
          if(coursenum < coursegraph.size() && 
              prereqnum < coursegraph.size()){
            
            coursegraph.add_edge(coursenum,prereqnum);
            std::cout <<"Course " << CourseGraph[prereqNum] 
              <<" is now a prerequisite to course "
            << CourseGraph[courseNum] << "\n";
          }else
            std::cout <<"One of your entries is invalid\n";
      
        break;
      }
      
      case 3:	// Remove a prerequisite relationship
      {
        std::cout <<"Enter a course number with a prerequisite\n";
        std::cin >> courseNum;
        std::cout <<"Enter the prerequisite course number\n";
        std::cin >> prereqNum;
          if(courseNum < CourseGraph.size() && prereqNum < CourseGraph.size()) {
            if(CourseGraph.is_edge(courseNum,prereqNum)) {
              CourseGraph.remove_edge(courseNum,prereqNum);
              std::cout <<"Course " <<CourseGraph.operator[](prereqNum)
              <<" has been removed as a prerequisite from course "
              <<CourseGraph[courseNum] <<"\n";
              } else
                std::cout <<"Course " <<CourseGraph.operator[](prereqNum)
                <<" is not a prerequisite to course "
                <<CourseGraph[courseNum] <<"\n";
          } else
            std::cout <<"One of your entries is invalid\n";
      }
        break;
      case 4:	// Report if a course is an immediate prerequisite of another
      {
          std::cout <<"Enter a course number: ";
          std::cin >> courseNum;
          std::cout << "\n";
          std::cout <<"Enter a possible prerequisite course number: ";
          std::cin >> prereqNum;
          std::cout << "\n";
          if (courseNum < CourseGraph.size() && prereqNum < CourseGraph.size()) {
              if (CourseGraph.is_edge(courseNum,prereqNum))
                  std::cout <<"Course " <<CourseGraph[prereqNum]
                  <<" is an immediate prerequisite to course "
                  <<CourseGraph[courseNum]<<"\n";
              else
                  std::cout <<"Course "
                  <<CourseGraph[prereqNum]
                  <<" is not an immediate prerequisite\n";
              }
              else
                  std::cout <<"One of your entries is invalid\n";
          
          break;
      }
              
      case 5:	// Report if there is a prerequisite path between two courses
      {
          std::cout <<"Enter a course number\n" <<std::endl;
          std::cin >> courseNum;
          std::cout <<"Enter a possible prerequisite course number\n" <<"\n";
          std::cin >> prereqNum;
          if (courseNum < CourseGraph.size() && prereqNum < CourseGraph.size())
          {
              if (CourseGraph.is_path(courseNum,prereqNum))
              {
                  std::cout <<"Course " <<CourseGraph[prereqNum]
                  <<" is on a prerequisite path to course "
                  <<CourseGraph.operator[](courseNum) << "\n";
              }
              else
                  std::cout <<"Course " <<CourseGraph[prereqNum] <<" is not on a prerequisite path\n";
              }
              else
                  std::cout <<"One of your entries is invalid\n";
         break;
      }
          // Display all courses which can be taken directly after a course
      case 6:	      {
          std::cout <<"Enter a course number\n" <<std::endl;
          std::cin >> courseNum;
          if (courseNum < CourseGraph.size())
          {
              std::cout <<"The following courses can be taken after Course number: "
              <<courseNum <<" Course: "
              <<CourseGraph[courseNum]<<"\n";
          
              for (size_t i = 0; i < CourseGraph.size(); i++)
              {
                  if (CourseGraph.is_edge(i,courseNum))
                      {
                          std::cout <<"Course number: " << i
                          <<" Course: " <<CourseGraph[i] <<"\n";
                      }
                  }
              }
              else
                  std::cout <<"Your entry is invalid\n";
          
          break;
          }
          // Display all courses
      case 7:	{
        for (size_t i = 0; i < CourseGraph.size(); i++)
          std::cout <<"Course number: " <<i <<" Course: " <<CourseGraph[i] <<"\n";
          break;
      }
      case 8: {
        std::cout << "Quiting the Program\n\n";
        exit(1);
        break;
      }
    }
    
  } while(choice < 9 && choice > 0);
  
  return 0;
}

void PrintMenu() {
  std::cout <<"------------------------------------------------------------------------\n";
  std::cout <<"1 - Enter a new course\n";
  std::cout <<"2 - Enter a prerequisite relationship\n";
  std::cout <<"3 - Remove a prerequisite relationship\n";
  std::cout <<"4 - Report if a course is an immediate prerequisite of another\n";
  std::cout <<"5 - Report if there is a prerequisite path between two courses\n";
  std::cout <<"6 - Display all courses which can be taken directly after a course\n";
  std::cout <<"7 - Display all courses\n";
  std::cout <<"8 - exit\n";
  std::cout <<"------------------------------------------------------------------------\n\n";
}
