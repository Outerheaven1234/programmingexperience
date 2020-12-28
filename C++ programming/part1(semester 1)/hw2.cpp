/***********************************************
  Author: Vibishan Wigneswaran
  Date: 10/4/2019
  Purpose: Read a input file and print the words in the file and replace the word "dislike" with "love".
  Time Spent: 45 minutes
   ***********************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
    ifstream inStream;
    ofstream outStream;
    inStream.open("input.txt");
    if(inStream.fail()){
      cout<<"Can't open file to read!"<< endl;
      exit(1);
    }

    string word;
    char letter;

    while(inStream >> word){
      if(word == "dislike"){
      cout << "love ";
      word.clear();
    }
      else{
        cout << word << " ";
      }
    }
    inStream.close();
    return 0;
}

/* Computing III -- COMP.2010 Honor Statement

The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation.  This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog.  Violations will be dealt with as outlined therein.

All programming assignments in this class are to be done by the student alone.  No outside help is permitted except the instructor and approved tutors.

I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.

Date: 10/4/2019
Name:Vibishan Wigneswaran
  */
