/***********************************************
  Author: Vibishan Wigneswaran
  Date: 12/9/2019
  Purpose: Modify and finish the given program.
  Time: 1 hour
   ***********************************************/
#include <iostream>
#include <string>
#include <exception>

using namespace std;

void testPFArrayD(void);
void testException(void);

//Exception class
class OutOfRange: public exception
{
public:
  OutOfRange(int a, string b):indexVal(a),message(b){ err(); }
  int index() const { return indexVal; }
  string err() const { cout << "Error "<< indexVal << ": " << message << endl; }
private:
  int indexVal;
  string message;
};

//Objects of this class are partially filled arrays of doubles.
class PFArrayD
{
public:
    PFArrayD();
    //Initializes with a capacity of 50.

    PFArrayD(int capacityValue);
    PFArrayD(const PFArrayD& pfaObject);

    void addElement(double element);
    //Precondition: The array is not full.
    //Postcondition: The element has been added.

    bool full() const { return (capacity == used); }
    //Returns true if the array is full, false otherwise.

    int getCapacity() const { return capacity; }
    int getNumberUsed() const { return used; }
    void emptyArray(){ used = 0; }
    //Empties the array.
    double& operator[](int index);
    //Read and change access to elements 0 through numberUsed - 1.
    PFArrayD& operator =(const PFArrayD& rightSide);
    ~PFArrayD();
private:
    double *a; //for an array of doubles.
    int capacity; //for the size of the array.
    int used; //for the number of array positions currently in use.
};

int main(int argc, char *argv[])
{
     cout << "This program tests the class PFArrayD.\n";
     char ans;
     do
     {
         testPFArrayD();
         cout << "Test again? (y/n) ";
         cin >> ans;
     }while ((ans == 'y') || (ans == 'Y'));
     testException(); //tests exception for Exceeding capacity
    return 0;
}

void testException(void)
{
  cout << "Testing Exceptions for exceeding capacity" << endl;
  //test exceeding capacity
  PFArrayD test(2);
  test.addElement(2);
  test.addElement(3);
  test.addElement(4);
  cout << "Testing Exceptions for illegal index" << endl;
  test[8];
}

void testPFArrayD()
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";

    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full()))
    {
        temp.addElement(next);
        cin >> next;
    }

    cout << "You entered the following " << temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed();
    for (index = 0; index < count; index++)
    cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}

//class member function definitions
PFArrayD::PFArrayD():capacity(50),used(0)
{
  a=new double[capacity];
}
//Initializes with a capacity of 50.

PFArrayD::PFArrayD(int capacityValue):capacity(capacityValue),used(0)
{
  a=new double[capacity];
}

PFArrayD::PFArrayD(const PFArrayD& pfaObject):capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
  a = new double[capacity];
    for (int i =0; i < used; i++)
    {
        a[i] = pfaObject.a[i];
    }
}

void PFArrayD::addElement(double element)
{
  try{
  if (used >= capacity)
    {
      throw(404);
    }
  }

    catch(int e){
      OutOfRange(e,"Exceeding capacity");
    }

    a[used] = element;
    used++;
}

//Empties the array.
double& PFArrayD::operator[](int index)
{
  try{
  if (index >= used)
    {
        throw(504);
    }
  }
  catch(int e){
    OutOfRange(e,"Illegal Index");
  }
    return a[index];
}
//Read and change access to elements 0 through numberUsed - 1.
PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide)
{
  if (capacity != rightSide.capacity)
    {
        delete [] a;
        a = new double[rightSide.capacity];
    }

    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++)
        a[i] = rightSide.a[i];

    return *this;
}
PFArrayD::~PFArrayD()
{
  delete[] a;
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
  
   Date:	12/9/19
  
   Name:	Vibishan Wigneswaran
  
   */
