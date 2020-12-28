/***********************************************
Author: Vibishan Wigneswaran
Date: 10/7/2019
 Purpose: Create an object class point and use functions to rotate and move a coordinate point.
 Time Spent: 1.5 hours
 ***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Point
{
public:
  Point(double inix = 0, double iniy = 0);  //sets private data to 0
  void movePoint(double movex, double movey); //shifts the point
  void rotate(); //rotates point

  //accessor functions for coordinates
  double getx(double x); //accessor for x coordinate
  double gety(double y); //accessor for y coordinate

private:
  double x; //x coordinate
  double y; //y coordinate
};

int main(int argc, char *argv[]){
  Point myPoint1, myPoint2, myPoint3;
  myPoint1=Point(1,2);
  myPoint1.rotate();
  myPoint1.rotate();
  myPoint1.rotate();
  myPoint1.rotate();

  myPoint2=Point(3,4);
  myPoint2.movePoint(1,1);

  myPoint3=Point(5,-4);
  myPoint3.movePoint(-5,4);
}

Point::Point(double inix, double iniy){
  x = inix;
  y = iniy;
}

void Point::movePoint(double movex, double movey){
  x += movex;
  y += movey;
}

void Point::rotate(){
  if(x>=0 && y>=0){
    x=-x;
  }
  else if(x>=0 && y<=0){
    y=-y;
  }
  else if(x<=0 && y<=0){
    x=-x;
  }
  else{
    y=-y; //even if it is 0,0 making y negative wont change outcome
  }
}

double getx(double x){
  return x;
}

double gety(double y){
  return y;
}

/* Computing III -- COMP.2010 Honor Statement

The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation.  This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog.  Violations will be dealt with as outlined therein.

All programming assignments in this class are to be done by the student alone.  No outside help is permitted except the instructor and approved tutors.

I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.

Date:10/7/2019
Name: Vibishan Wigneswaran
*/
