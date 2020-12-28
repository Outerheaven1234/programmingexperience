/***********************************************
Author: Vibishan Wigneswaran
Date: 10/21/2019
Purpose: overload functions + verify it with a driver
Time Spent: 4 hours
***********************************************/
//libraries
#include <iostream>

using namespace std;

//class for Rational
class Rational
{
public:
	//constructors
	Rational()
	{
		numerator = 0;
		denominator = 1;
	}
	Rational(int wholeNumber)
	{
		numerator = wholeNumber;
		denominator = 1;
	}
	Rational(int newNumerator, int newDenominator)
	{
		numerator = newNumerator;
		denominator = newDenominator;
	}
	Rational(const Rational& newFrac)
	{
		numerator = newFrac.numerator;
		denominator = newFrac.denominator;
	}
  //destructor
	~Rational()
	{
	}

	//set numerator and denominator consecutivly
	void setOrder(int num1, int num2)
	{
		if (num1 == NULL)
		{
			Rational();
		}
		numerator = num1;

		if (num2 == NULL)
		{
			Rational(num1);
		}
		denominator = num2;
	}

	//Display the fraction
	void print()
	{
		cout << numerator << "/" << denominator << endl;
	}

	//accessors
	int getNumerator()
	{
		return this->numerator;
	}
	int getDenominator()
	{
		return this->denominator;
	}

  //mutators
	void setNumerator(int newnum)
	{
		numerator = newnum;
	}
	void setDenominator(int newnum)
	{
		while (newnum == 0)
		{
			cout << "The denominatorinator cannot be equal to 0. Please try again: ";
			cin >> newnum;
		}
		denominator = newnum;
	}


	//assignment overload needs to be member function for ease of use
	void operator=(const Rational& compare)
	{
		numerator = compare.numerator;
		denominator = compare.denominator;
	}

	friend const Rational operator+(Rational num1, Rational num2);
	friend const Rational operator-(Rational num1, Rational num2);
	friend const Rational operator/(Rational num1, Rational num2);
	friend const Rational operator*(Rational num1, Rational num2);

	friend const bool operator==(Rational& num1, Rational& num2);
	friend const bool operator!=(Rational& num1, Rational& num2);
	friend const bool operator<=(Rational& num1, Rational& num2);
	friend const bool operator>=(Rational& num1, Rational& num2);
	friend const bool operator>(Rational& num1, Rational& num2);
	friend const bool operator<(Rational& num1, Rational& num2);

private:
	//private variables
	int numerator;
	int denominator;

	//simplify a fraction
	int simplify(Rational& other)
	{
		if (getDenominator() == other.getDenominator()) {
			return getDenominator();
		}
		int numerator1 = getNumerator();
		int numerator2 = other.getNumerator();

		setNumerator(numerator1 * other.denominator);
		other.setNumerator(numerator2 * denominator);

		int newdenominator = denominator * other.denominator;

		setDenominator(newdenominator);
		other.setDenominator(newdenominator);
		return newdenominator;
	}
};

//overloaing operators/friend functions
const Rational operator+(Rational num1, Rational num2)
{
	Rational result;

	int newdenominator = num1.simplify(num2);
	int newnumerator = num1.getNumerator() + num2.getNumerator();
	result.setOrder(newnumerator, newdenominator);

	return result;
}
const Rational operator-(Rational num1, Rational num2)
{
	Rational result;

	int newdenominator = num1.simplify(num2);
	int newnumerator = num1.getNumerator() - num2.getNumerator();

	result.setOrder(newnumerator, newdenominator);

	return result;
}
const Rational operator*(Rational num1, Rational num2)
{
	Rational result;
	int newdenominator;
	int newnumerator;

	newdenominator = (num1.getDenominator() * num2.getDenominator());
	newnumerator = num1.getNumerator() * num2.getNumerator();

	result.setOrder(newnumerator, newdenominator);

	return result;
}
const Rational operator/(Rational num1, Rational num2)
{
	Rational result;
	int newdenominator;
	int newnumerator;

	num2.setOrder(num2.getDenominator(), num2.getNumerator());
	newdenominator = (num1.getDenominator() * num2.getDenominator());
	newnumerator = num1.getNumerator() * num2.getNumerator();

	result.setOrder(newnumerator, newdenominator);

	return result;
}
const bool operator==(Rational& num1, Rational& num2)
{
	num1.simplify(num2);

	if (num1.getNumerator() == num2.getNumerator())
	{
		return true;
	}
	return false;
}
const bool operator!=(Rational& num1, Rational& num2)
{
	num1.simplify(num2);

	if (num1.getNumerator() != num2.getNumerator())
	{
		return true;
	}
	return false;
}
const bool operator>=(Rational& num1, Rational& num2)
{
	num1.simplify(num2);

	if (num1.getNumerator() != num2.getNumerator())
	{
		return true;
	}
	return false;
}
const bool operator<=(Rational& num1, Rational& num2)
{
	num1.simplify(num2);

	if (num1.getNumerator() <= num2.getNumerator())
	{
		return true;
	}
	return false;
}
const bool operator>(Rational& num1, Rational& num2)
{
	num1.simplify(num2);

	if (num1.getNumerator() > num2.getNumerator())
	{
		return true;
	}
	return false;
}
const bool operator<(Rational& num1, Rational& num2)
{
	num1.simplify(num2);

	if (num1.getNumerator() < num2.getNumerator())
	{
		return true;
	}
	return false;
}

//shift operators
ostream& operator<<(ostream& os, Rational& rShift)
{
	const int numerator = rShift.getNumerator();
	const int denominator = rShift.getDenominator();

	os << numerator << "/" << denominator << " cout " << endl;

	return os;
}
istream& operator>>(istream& os, Rational& rShift)
{
	int newnum;

	//what cin should be doing
	cout << "Enter numeratorator: ";
	cin >> newnum;
	rShift.setNumerator(newnum);
	cout << "Enter denominatorinator: ";
	cin >> newnum;
	rShift.setDenominator(newnum);

	cout << rShift.getNumerator() << '/' << rShift.getDenominator() << endl << " cin " << endl;

	return os;
}

//driver to test operators

int main(int argc, char argv[])
{
  //2 rational objects are initalized
	Rational rat1(-6, 9);
	Rational rat2(8);

	cout << "rat1 created";  rat1.print();
	cout << "rat2 created"; rat2.print();
	cout << endl;

	//operator check
	Rational Add = rat1 + rat2;
	cout << "rat1 + rat2:" << endl;
	Add.print();

	Rational Sub = rat1 - rat2;
	cout << "rat1 - rat2:" << endl;
	Sub.print();

	Rational mult = rat1 * rat2;
	cout << "rat1 * rat2:" << endl;
	mult.print();

	Rational div = rat1 / rat2;
	cout << "rat1 / rat2:" << endl;
	div.print();

	cout << endl;

	//check constructors
	Rational copy(rat1);
	Rational cinInit(1, 2);

	if (copy == rat1)
	{
		cout << "copy constructor verified" << endl;
	}
	else if (copy != rat1)
	{
		cout << "copy constructor failed to work" << endl;
	}

	//comparison operators
	if (rat1 == rat2)
	{
		cout << "rat1 != rat2" << endl;
	}
	else if (rat1 != rat2)
	{
		cout << "rat1 = rat2" << endl;
	}

	if (rat1 >= rat2)
	{
		cout << "rat1 >= rat2" << endl;
	}
	else if (rat2 >= rat1)
	{
		cout << "rat2 >= rat1" << endl;
	}

	if (rat1 > rat2)
	{
		cout << "rat1 > rat2" << endl;
	}
	else if (rat2 > rat1)
	{
		cout << "rat2 > rat1" << endl;
	}

	cout << endl << "Printing rat1: " << endl << rat1 << endl;

	//verifies assignment operator
	cout << "rat1=(set to)rat2: " << endl;
	rat1 = rat2;
	cout << "rat1: " << rat1;
	cout << "rat2: " << rat2 << endl;

	cout << "creating new class using cin" << endl;
	cin >> cinInit;

	return 0;
}

/* Computing III -- COMP.2010 Honor Statement

The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation.  This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog.  Violations will be dealt with as outlined therein.

All programming assignments in this class are to be done by the student alone.  No outside help is permitted except the instructor and approved tutors.

I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.

Date: 10/21/2019
Name: Vibishan Wigneswaran
*/ 
