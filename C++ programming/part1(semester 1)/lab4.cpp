// Group:Vibishan, Lucien, Jeremy 10/8/2019
// Lab 4
#include <iostream>
#include <string>

using namespace std;


// ***** Add your Date class definition and driver program at the end of this file
// (at about line 107). *****

// The Month class provided below is a "helper" class for your Date class.
// Note that although both classes are defined in this single compilation unit (file),
// we are not nesting the Month class in the Date class or vice versa.

class Month {
	friend class Date;

	friend ostream& operator<< (ostream&, Month);

    private:
        enum EMonth { Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

        Month() : _month(Jan) {} // default constructor
        Month(int im) : _month( static_cast<EMonth>(im) ) {} // value constructor

        void setMonth(string m) { _month = StringToEMonth(m); } // mutator functions
		void setMonth(int im) { _month = static_cast<EMonth>(im); }

		/* Private helper member functions */
        EMonth StringToEMonth(string);
        int MonthToInt() { return static_cast<int>(_month); }
		string MonthToString();
		string MonthToString2();

	    EMonth _month;
};

/* Definitions of helper member functions for class Month */

Month::EMonth Month::StringToEMonth(string m) {
	if (m == "Jan") return Jan;
	else if (m == "Feb") return Feb;
	else if (m == "Mar") return Mar;
	else if (m == "Apr") return Apr;
	else if (m == "May") return May;
	else if (m == "Jun") return Jun;
	else if (m == "Jul") return Jul;
	else if (m == "Aug") return Aug;
	else if (m == "Sep") return Sep;
	else if (m == "Oct") return Oct;
	else if (m == "Nov") return Nov;
	else if (m == "Dec") return Dec;
	else {
		cerr << "Month::StringToMonth: Invalid input month \"" << m << "\"\n";
		exit(1);
	}
}

string Month::MonthToString() {
	switch (_month) {
		case Jan: return "Jan";
		case Feb: return "Feb";
		case Mar: return "Mar";
		case Apr: return "Apr";
		case May: return "May";
		case Jun: return "Jun";
		case Jul: return "Jul";
		case Aug: return "Aug";
		case Sep: return "Sep";
		case Oct: return "Oct";
		case Nov: return "Nov";
		case Dec: return "Dec";
		default:
			cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
			exit(1);
	}
}

string Month::MonthToString2() {
	switch (_month) {
		case Jan: return "January";
		case Feb: return "February";
		case Mar: return "March";
		case Apr: return "April";
		case May: return "May";
		case Jun: return "June";
		case Jul: return "July";
		case Aug: return "August";
		case Sep: return "September";
		case Oct: return "October";
		case Nov: return "November";
		case Dec: return "December";
		default:
			cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
			exit(1);
	}
}

/* Definition of friend function operator<< */

ostream& operator<< (ostream& out, Month m) {
	out << m.MonthToString2();
	return out;
}
class Date{
	friend ostream& operator <<(ostream& output, Date d);

public:
	Date();
	Date operator ++();
	void setDate(int month, int day, int year);
	void setDateA(string month, int day, int year);

	void changeMonth(int x);



	outputDateAsInt(ostream&);
	outputDateAsString(ostream&);

private:
	Month month;
	int day;
	int year;


};


main(){

		Date d1, d2, d3, d4;

		d1.outputDateAsInt(cout);
		d2.setDate(2, 1, 2018);
		d3.setDateA("Mar", 1, 2019);
		d4.setDate(12, 31, 2018);
    cout << "With the following declarations: " << endl
         << "\tDate d1, d2(2, 1, 2018), d3(\"Mar\", 1, 2018);" << endl
         << "...and using operator<< :" << endl;

    cout << "d1 == ";
    d1.outputDateAsString(cout);

    cout << "d2 == ";
    d2.outputDateAsString(cout);

    cout << "d3 == ";
    d3.outputDateAsString(cout);

    cout << endl;

    d3.changeMonth(4);
    cout << "After d3.setMonth(4): " << endl << "d3 == ";
    d3.outputDateAsString(cout);

    cout << "With the following declaration:" << endl
         << "\tDate d4(12, 31, 2018)" << endl;

    cout << "d4.OutputDateAsInt(cout) outputs ";
    d4.outputDateAsInt(cout);
    cout << "d4.OutputDateAsString(cout) outputs ";
    d4.outputDateAsString(cout);

    cout << endl;

    ++d4;
    cout << "++d4 == ";
    d4.outputDateAsString(cout);

    return 0;
}



// ***** Add your Date class definition and driver program below. *****
Date::Date(){

	Date::day = 1;
	Date::year = 2018;
}
void Date::setDate(int month, int day, int year){
	Date::month.setMonth(month);
	Date::day = day;
	Date::year = year;
}
void Date::setDateA(string month, int day, int year){
  Date::month.setMonth(month);
	Date::day = day;
	Date::year = year;
}
Date Date::operator ++()
{
 year++;
 return *this;
}
void Date::changeMonth(int x){
	Date::month.setMonth(x);
}

ostream& operator <<(ostream& output, Date d){
cout<<	d;
}

Date::outputDateAsInt(ostream& out){
	out << Date::month << "/" << Date::day << "/" << Date::year << endl;
}

Date::outputDateAsString(ostream& out){
	out << month.MonthToString2() << " " << Date::day << ", " << Date::year << " " << endl;
}
