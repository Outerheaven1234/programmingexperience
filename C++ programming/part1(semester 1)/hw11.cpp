/***********************************************
  Author: Vibishan Wigneswaran
  Date: 12/10/2019
  Purpose: Create a program that permutes a string of numbers or characters and excludes duplicate Perm.
  Time: 5 hours
   ***********************************************/
 //libraries
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

//function Precondition
vector<string> generate_permutations(list<string> newList);
void print_permutations(vector<string> v);

//function for extra credit that check duplicates
bool checkDup(vector<string> v, string newStr);

int main(int argc, char*argv[])
{
	list<string> inputList;
	string aLine, aString;// read in strings from
	cout<< "Enter strings, separated by a space:";
	getline(cin, aLine); //read a line from keyboard
	istringstream iss(aLine); //convert aLine to an istringstream obj

	//parse each string
	while(iss >> aString)
	{
		inputList.push_back(aString);
	}

	auto Perm = generate_permutations(inputList);

  //print Perm
	print_permutations(Perm);
	return 0;
}

//generates Perm
vector<string> generate_permutations(list<string> newList)
{
	vector<string> Perm;
	string temp;
	vector<string> newArray;
	for(string newStr : newList)
	{
		if (!checkDup(newArray, newStr))
		{
			newArray.push_back(newStr);
		}
	}
	sort(newArray.begin(), newArray.end());
	do {
		for (size_t i = 0; i < newArray.size(); i++)
		{
			temp.append(newArray[i]);
			temp.append(" ");
		}
		Perm.push_back(temp);
		temp = "";
	} while (next_permutation(newArray.begin(), newArray.end()));

	return Perm;
}

//prints each permutation
void print_permutations(vector<string> v)
{
	cout << "Permutations are: \n";
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << (i+1) << ": " << v.at(i) << endl;
	}
}

//checks vector for duplicates
bool checkDup(vector<string> v, string newStr)
{
	for (string s : v)
	{
		if (newStr.compare(s) == 0)
			return true;
	}
	return false;
}

/*
   Computing
  III
  -­‐-­‐
  COMP.2010
  Honor
  Statement
  
   The
  practice
  of
  good
  ethical
  behavior
  is
  essential
  for
  maintaining
   good
  order
  in
  the
  classroom,
  providing
  an
  enriching
  learning
   experience
  for
  students,
  and
  as
  training
  as
  a
  practicing
  computing
   professional
  upon
  graduation.
  
  This
  practice
  is
  manifested
  in
  the
   University’s
  Academic
  Integrity
  policy.
  Students
  are
  expected
  to
   strictly
  avoid
  academic
  dishonesty
  and
  adhere
  to
  the
  Academic
   Integrity
  policy
  as
  outlined
  in
  the
  course
  catalog.
  
  Violations
  will
   be
  dealt
  with
  as
  outlined
  therein.
  
   All
  programming
  assignments
  in
  this
  class
  are
  to
  be
  done
  by
  the
   student
  alone.
  
  No
  outside
  help
  is
  permitted
  except
  the
  instructor
  and
   approved
  tutors.
  
   I
  certify
  that
  the
  work
  submitted
  with
  this
  assignment
  is
  mine
  and
  was
   generated
  in
  a
  manner
   consistent
  with
  this
  document,
  the
  course
   academic
  policy
  on
  the
  course
  website
  on
  Blackboard,
  and
  the
  UMass
   Lowell
  academic
  code.
  
   Date:	12/10/19
  
   Name:	Vibishan Wigneswaran
  
   */
