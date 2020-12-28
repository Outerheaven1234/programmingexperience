/***********************************************
Author: Vibishan Wigneswaran
Date: 11/6/2019
Purpose: Create a class called DynamicStringArray that allows it to emulate the behavior of a vector of strings
Sources of Help:
Time Spent: 2.5 hours
 ***********************************************/
 #include<string>
 #include<iostream>
 #include<string>

 using namespace std;
 //create class for DynamicStringArray
 class DynamicStringArray
 {
 //private variables
 private:
 string *dynamicArray;
 int size;
 //public (constructors, member functions, etc)
 public:
 DynamicStringArray(); //default constructor
 DynamicStringArray(DynamicStringArray& strArr); //copy constructor
 ~DynamicStringArray(); //default destructor
 //returns size
 int getSize()
 {
 return size;
 }
 void addEntry(string newStr);
 bool deleteEntry(string str);
 string getEntry(int index);
 };

 int main(){
   //Program driver to test the functions
    DynamicStringArray Arr;

    string str = "String", str1 = "Stringone", str2 = "Stringtwo", str3 = "Stringthree", str4 = "Stringfour";

    Arr.addEntry(str);
    Arr.addEntry(str1);
    Arr.addEntry(str2);
    Arr.addEntry(str3);
    Arr.deleteEntry(str2);
    Arr.addEntry(str4);
    cout << Arr.getEntry(2) << endl;
    cout << Arr.getSize() << endl;
    Arr.addEntry(str2);
    cout << Arr.getSize() << endl;
    cout << Arr.getEntry(0) << endl;
    cout << Arr.getEntry(1) << endl;
    cout << Arr.getEntry(2) << endl;
    cout << Arr.getEntry(3) << endl;
    cout << Arr.getEntry(4) << endl;

    return 0;
 }

 //default constructor
 DynamicStringArray::DynamicStringArray()
 {
 this->dynamicArray = NULL;
 this->size = 0;
 }

 //copy constructor
 DynamicStringArray::DynamicStringArray(DynamicStringArray& strArr)
 {
 this->size = strArr.getSize();
 string *tempArray = new string[size];
 for(int i = 0; i < size; i++)
 {
 tempArray[i] = strArr.getEntry(i);
 }
 this->dynamicArray = tempArray;
 }
 //destructor
 DynamicStringArray::~DynamicStringArray()
 {
 if(dynamicArray != NULL)
 delete [] dynamicArray;
 }
 //adds a new entry to the array
 void DynamicStringArray::addEntry(string newStr)
 {
 if(size == 0)
 {
 //checks array size
 size++;
 dynamicArray = new string[1];
 dynamicArray[0] = newStr;
 }
 else
 {
 string *tempArray = new string[size+1];
 for(int i = 0; i < size; i++)
 {
 tempArray[i]=dynamicArray[i];
 }
 tempArray[size] = newStr; //adds new string
 delete [] dynamicArray; //deletes dynamic array
 size++;
 dynamicArray = tempArray;
 }
 }
 //deletes an entry from an array
 bool DynamicStringArray::deleteEntry(string str)
 {
 string *tempArray = new string[size - 1];
 bool found = false;
 int count = 0;
 //checks if array is empty
 if(size == 0)
 return false;
 for(int i = 0; i < size; i++)
 {
 if(dynamicArray[i].compare(str) == 0)
 {
 found = true;
 }
 else
 {
 tempArray[count] = dynamicArray[i];
 count++;
 }
 }
 delete [] dynamicArray;
 size--;
 dynamicArray = tempArray;
 //checks array
 return found;
 }
 //returns the string at given index
 string DynamicStringArray::getEntry(int index)
 {
 if(index < 0)
 return NULL;
 else if(index > this->size)
 return NULL;
 else
 return this->dynamicArray[index];
 };

/* Computing III -- COMP.2010 Honor Statement

The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation.  This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog.  Violations will be dealt with as outlined therein.

All programming assignments in this class are to be done by the student alone.  No outside help is permitted except the instructor and approved tutors.

I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.

Date: 11/6/2019
Name: Vibishan Wigneswaran
*/
