/***********************************************
  Author: Vibishan Wigneswaran
  Date: 11/18/2019
  Purpose: Read a list of movie ratings and find the averages for each movie and output the ratings
  Sources: www.cplusplus.com/reference for unique and sorting function for list Library
  Time Spent: couple of hours

   ***********************************************/

#include <iostream>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <list>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
  //read txt file
  ifstream inStream;
  ofstream outStream;
  inStream.open("HW07.txt");
  //error message if fails
  if(inStream.fail()){
    cout<<"Can't open file to read!"<< endl;
    exit(1);
  }

  //creates map for rating and movie
  map<int, int> rating;
  map<int, string> movie;

  //retreives number of reviews from txt file
  string temp;
  int numRating;
  getline(inStream, temp);
  numRating = stoi(temp);

  //inputs data from text file to maps
  int i;
  for(i=0; i<numRating; i++){
    string a;
    string b;
    int rate;
    getline(inStream, a);
    getline(inStream, b);
    rate = stoi(b);
    movie.insert(pair <int, string>(i, a));
    rating.insert(pair <int, int>(i, rate));
  }

  //creates list for movie titles
  list<string> l;

  //creates iterators for maps
  map<int,string>::iterator itr;
  map<int,int>::iterator it;

  //inputs movies from movie map to list
  for(itr=movie.begin();itr!=movie.end();++itr)
  {
    l.push_back(itr->second);
  }

  //sorts movies and gets rid of duplicates
  l.sort();
  l.unique();

  //iterates each movie title once
  for(auto x : l)
  {
    double sum=0;
    int i = 0;
    //iterates movie title map
    for(itr=movie.begin();itr!=movie.end();++itr)
    {
      //if movie title from list is found in map
      if(x==(itr->second)){
        int y = itr->first;
        //uses key from movie map to find movie's rating in rating map
        it=rating.find(y);
        //adds ratings for movies
        sum+=(it->second);
        i++; //counts number of reviews per movie
      }
    }
    //prints movie title, numer of reviews, and average rating for the movie
    cout << x << ": " << i << " reviews, an average rating of " << sum/i << "/5" <<endl;
  }
}

/* Computing III -- COMP.2010 Honor Statement

The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation.  This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog.  Violations will be dealt with as outlined therein.

All programming assignments in this class are to be done by the student alone.  No outside help is permitted except the instructor and approved tutors.

I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.

Date: 11/18/2019
Name:Vibishan Wigneswaran
  */
