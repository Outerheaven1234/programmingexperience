/***********************************************
  Author: Vibishan Wigneswaran
  Date: 11/26/2019
  Purpose: Creat classes vehicle, truck and person and test the classes
  Time Spent: 2hours

   ***********************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

class Person {
  public:
    Person():name("empty"){}
    Person(string theName):name(theName){}
    Person(const Person& theObject):name(theObject.name){}
    string getName() const{ return name;}
    Person& operator=(const Person& rtSide);
    void print();
    friend istream& operator >>(istream& inStream, Person& personObject);
    friend ostream& operator <<(ostream& outStream, const Person& pObject);
    private:
      string name;
    };

class Vehicle
{
public:
  Vehicle():manuName("unknown"), cylinders(0), Owner(Person()){}
  Vehicle(string newName, int numCyl, Person newOwner): manuName(newName), cylinders(numCyl), Owner(newOwner){}
  Vehicle(const Vehicle &obj);
  string getManuname() const{ return manuName;}
  int getCylinders() const{ return cylinders;}
  Person getOwner() const{ return Owner;}
  Vehicle& operator=(const Vehicle &obj);
  void print();
  friend istream& operator >>(istream& inStream, Vehicle& vehicleObject);
  friend ostream& operator <<(ostream& outStream, const Vehicle& vehicleObject);
protected:
  string manuName;
  int cylinders;
  Person Owner;
};

class Truck: public Vehicle
{
public:
  Truck():loadCap(0.0), towCap(0){}
  Truck(double newloadcap, int newtowCap, string manuName, int numCyl, string name): loadCap(newloadcap), towCap(newtowCap), Vehicle(manuName, numCyl, Person(name)){}
  Truck(const Truck &obj);
  double getloadCap() const{ return loadCap;}
  int gettowCap() const{ return towCap;}
  Truck& operator=(const Truck& obj);
  void print();
  friend istream& operator >>(istream& inStream, Truck& truckObject);
  friend ostream& operator <<(ostream& outStream, const Truck& truckObject);
private:
  double loadCap;
  int towCap;
};

int main(int argc, char *argv[]){
  //Testing class person
  cout << "Testing Person Class" << endl << endl;
  Person newPerson;
  Person copyPerson;
  cout << "testing default constructor: " << endl;
  newPerson.print();
  newPerson = Person("Vibi");
  cout << "testing constructor(string): " << endl;
  newPerson.print();
  copyPerson = Person(newPerson);
  cout << "testing copy constructor: " << endl;
  copyPerson.print();
  cout << "testing >> overloading: " << endl << "Enter your name: ";
  cin >> newPerson;
  cout << "Your name is: " << endl;
  newPerson.print();
  copyPerson = newPerson;
  cout << "testing = overloading operator: " << endl;
  copyPerson.print();

  //Testing class Vehicle
  cout << "Testing Vehicle Class" << endl << endl;
  Vehicle newVehicle;
  Vehicle copyVehicle;
  cout << "testing default constructor: " << endl;
  newVehicle.print();
  newVehicle = Vehicle("Honda", 4, newPerson);
  cout << "testing constructor(string, int, owner): " << endl;
  newVehicle.print();
  copyVehicle = Vehicle(newVehicle);
  cout << "testing copy constructor: " << endl;
  copyVehicle.print();
  copyVehicle = newVehicle;
  cout << "testing = overloading operator: " << endl;
  copyVehicle.print();

  //Testing class Truck
  cout << "Testing Truck Class" << endl << endl;
  Truck newTruck;
  Truck copyTruck;
  cout << "testing default constructor: " << endl;
  newTruck.print();
  newTruck = Truck(120.25, 100, "BMW", 18, "Vibi");
  cout << "testing constructor(double, int, string, int, string): " << endl;
  newTruck.print();
  copyTruck = Truck(newTruck);
  cout << "testing copy constructor: " << endl;
  copyTruck.print();
  copyTruck = newTruck;
  cout << "testing = overloading operator: " << endl;
  copyTruck.print();
  return 0;
}

//Person
Person &Person::operator=(const Person& rtSide)
{
  this->name = rtSide.name;
  return *this;
}

istream &operator >>(istream &inStream, Person &personObject)
{
  inStream >> personObject.name;
  return inStream;
}

ostream &operator <<(ostream &outStream, const Person &personObject)
{
  outStream << personObject.name;
  return outStream;
}

// Vehicle
Vehicle::Vehicle(const Vehicle &obj)
{
  manuName=obj.manuName;
  cylinders=obj.cylinders;
  Owner=obj.Owner;
}

Vehicle &Vehicle::operator=(const Vehicle &obj)
{
  this->manuName=obj.manuName;
  this->cylinders=obj.cylinders;
  this->Owner=obj.Owner;
  return *this;
}

istream& operator >>(istream &inStream, Vehicle &vehicleObject)
{
  inStream >> vehicleObject.manuName;
  inStream >> vehicleObject.cylinders;
  inStream >> vehicleObject.Owner;
  return inStream;
}

ostream& operator <<(ostream &outStream, const Vehicle &vehicleObject)
{
  outStream << vehicleObject.manuName;
  outStream << vehicleObject.cylinders;
  outStream << vehicleObject.Owner;
  return outStream;
}

// Truck
Truck::Truck(const Truck &obj):Vehicle(obj)
{
  loadCap=obj.loadCap;
  towCap=obj.towCap;
}

Truck& Truck::operator=(const Truck &obj)
{
  loadCap=obj.loadCap;
  towCap=obj.towCap;
}

istream& operator >>(istream &inStream, Truck &truckObject)
{
  inStream >> truckObject.loadCap;
  inStream >> truckObject.towCap;
  return inStream;
}

ostream& operator <<(ostream &outStream, const Truck &truckObject)
{
  outStream << truckObject.loadCap;
  outStream << truckObject.towCap;
  return outStream;
}

//print functions(overloaded)
void Person::print(){
  cout << "name: " << this->getName()<< endl << endl;
}

void Vehicle::print(){
  cout << "Manufacturer: " << this->getManuname()<< endl;
  cout << "Number of cylinders: " << this->getCylinders()<< endl;
  cout << "Name of Owner: " << this->getOwner()<< endl << endl;
}

void Truck::print(){
  cout << "Manufacturer: " << this->getManuname()<< endl;
  cout << "Number of cylinders: " << this->getCylinders()<< endl;
  cout << "Name of Owner: " << this->getOwner()<< endl;
  cout << "Load Capacity: " << this->getloadCap()<< endl;
  cout << "Tow Capacity: " << this->gettowCap()<< endl << endl;
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
  
   Date:	11/26/19
  
   Name:	Vibishan Wigneswaran
  
   */
