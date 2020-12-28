//Vibishan Wigneswaran
//Dylan Stewart

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// using declarations
using std::ostream;
using std::cout;
using std::endl;
using std::string;


class PayKind { // base class - no member variables
public:
	void output(ostream& out) const { out << *this; }
	virtual double payAdvice()=0;

	friend ostream& operator<< (ostream&, const PayKind&);
};


class Salaried : public PayKind { // derived class
public:
	// constructors/destructor
	Salaried() : _annualSalary(0) {}
	Salaried(unsigned salary) : _annualSalary(salary) {}
	~Salaried() { cout << "Salaried destructor called\n"; }
	double payAdvice() { return (_annualSalary/26);}
	// accessor functions
	unsigned getSalary() const { return _annualSalary; }

	void output(ostream& out) const { out << *this; }

	friend ostream& operator<< (ostream&, const Salaried&);

private:
	unsigned _annualSalary;
};


class Hourly : public PayKind { // derived class
public:
	// constructors/destructor
	Hourly() : _hourlyRate(0) {}
	Hourly(unsigned hourlyRate) : _hourlyRate(hourlyRate) {}
	~Hourly() { cout << "Hourly destructor called\n"; }

	double payAdvice() {return (_hourlyRate*40);};

	// accessor functions
	unsigned getHourlyRate() const { return _hourlyRate; }

	void output(ostream& out) const { out << *this; }

	friend ostream& operator<< (ostream&, const Hourly&);

private:
	unsigned _hourlyRate;
};


ostream& operator<< (ostream& out, const PayKind& p) {
	out << "Paykind (no member variables)\n" << endl;

	return out;
}

ostream& operator<< (ostream& out, const Salaried& s) {
	out << "Salary:\t\t" << s.getSalary() << endl;

	return out;
}

ostream& operator<< (ostream& out, const Hourly& s) {
	out << "Hourly Rate:\t" << s.getHourlyRate() << endl;

	return out;
}


class UMLPerson { // base class
public:
	// constructors and destructor
	UMLPerson() : _firstName("NoName"), _lastName("NoName"), _address("NoAddress"), _IDNumber_(0) {}

	UMLPerson(string firstName, string lastName, string address, unsigned _IDNumber) :
		_firstName(firstName), _lastName(lastName), _address(address), _IDNumber_(_IDNumber) {}

	UMLPerson(const UMLPerson&); // copy constructor

	~UMLPerson();

	// accessor functions
	string getFirstName() const { return _firstName; }
	string getLastName() const { return _lastName; }
	string getAddress() const { return _address; }
	unsigned get_IDNumber() const { return _IDNumber_; }

	void output(ostream& out) const { out << *this; }

	friend ostream& operator<< (ostream&, const UMLPerson&);

private:
	string _firstName;
	string _lastName;
	string _address;
	unsigned _IDNumber_;
};


class Student : public UMLPerson { // derived class
public:
	// constructors and destructor
	Student() : UMLPerson() { _GPA = 0.0; _smajor = "Undeclared"; _advisorName = "NoName"; }

	Student(string firstName, string lastName, string address, unsigned _IDNumber,
		double GPA, string smajor, string advisorName);

	Student(const Student&); // copy constructor

	~Student();

	void output(ostream& out) const { out << *this; }

	// accessor functions
	double getGPA() const { return _GPA; }
	string getSmajor() const { return _smajor; }
	string getAdvisorName() const { return _advisorName; }

	friend ostream& operator<< (ostream&, const Student&);

private:
	double _GPA;
	string _smajor;
	string _advisorName;
};


class Undergrad : public Student { // derived class
public:
	// constructors and destructor
	Undergrad() : Student() { _classRank = "NoRank"; }

	Undergrad(string firstName, string lastName, string address, unsigned _IDNumber,
		double GPA, string smajor, string advisorName, string classRank);

	Undergrad(const Undergrad&); // copy constructor

	~Undergrad();

	void output(ostream& out) const { out << *this; }

	// accessor functions
	string getClassRank() const { return _classRank; }

	friend ostream& operator<< (ostream&, const Undergrad&);

private:
	string _classRank; // freshman, sophomore, junior, or senior
};

class EmployeeKind
{
public:
	void output(ostream& out) const { out << *this; }

	friend ostream& operator<< (ostream& out, const EmployeeKind& m);
};

ostream& operator<< (ostream& out, const EmployeeKind& m)
{
	out << "EmployeeKind has no member variables" << endl;

	return out;
}

class PartTime : public EmployeeKind
{
public:
	PartTime() : _maxHours(0) {};
	PartTime(unsigned iMax) : _maxHours(iMax) {};
	~PartTime() {cout << "Part time deconstructor called" << endl; }

	unsigned getMax(void) const { return _maxHours; }
	void output(ostream& out) { out << *this; }
	friend ostream& operator<<(ostream& out, PartTime& m);

private:
	unsigned _maxHours;

};

ostream& operator<<(ostream& out, PartTime& m)
{
	out << "Max hours: " << m.getMax() << endl;

	return out;
}

class Grader : public PartTime, public Undergrad, public Hourly
{ // derived class
public:
	// constructors and destructor
	Grader() : Undergrad() { _classNumber = "NoClassNumber"; }

	Grader(string firstName, string lastName, string address, unsigned _IDNumber,
		double GPA, string smajor, string advisorName, string classRank,
		string classNumber, unsigned hourlyRate, unsigned maxHours);

	Grader(const Grader&); // copy constructor

	~Grader();

	void output(ostream& out) const { out << *this; }

	// accessor functions
	string getClassNumber() const { return _classNumber; }

	friend ostream& operator<< (ostream&, const Grader&);

private:
	string _classNumber; // e.g., COMP.2010
};


class Employee : public UMLPerson { // derived class
public:
	// constructors and destructor
	Employee() : UMLPerson() { _SSN = "NoSSN"; }

	Employee(string firstName, string lastName, string address, unsigned _IDNumber,
		string SSN);

	//	    Employee(const Employee&); // copy constructor

	~Employee() { cout << "Employee destructor called\n"; }

	void output(ostream& out) const { out << *this; }

	// accessor functions
	string getSSN() const { return _SSN; }

	friend ostream& operator<< (ostream&, const Employee&);

private:
	string _SSN;
};


class Faculty : public Employee { // derived class
public:
	// constructors and destructor
	Faculty() : Employee() { _department = "NoDepartment"; }

	Faculty(string firstName, string lastName, string address, unsigned _IDNumber,
		string SSN, string department);

	//	    Faculty(const Faculty&); // copy constructor

	~Faculty() { cout << "Faculty destructor called for " << getFirstName() + " " + getLastName() << endl; }

	void output(ostream& out) const { out << *this; }

	// accessor functions
	string getDepartment() const { return _department; }

	friend ostream& operator<< (ostream&, const Faculty&);

private:
	string _department;
};


class NTT : public Faculty, public Salaried { // derived class
public:
	// constructors and destructor
	NTT() : Faculty(), Salaried() { _rank = "NoRank"; }

	NTT(string firstName, string lastName, string address, unsigned _IDNumber,
		string SSN, string department, string rank, unsigned salary);

	//	    NTT(const Faculty&); // copy constructor

	~NTT() { cout << "NTT destructor called for " << getFirstName() + " " + getLastName() << endl; }

	void output(ostream& out) const { out << *this; }

	// accessor functions
	string getRank() const { return _rank; }

	friend ostream& operator<< (ostream&, const NTT&);

private:
	string _rank; // lecturer or senior lecturer
};

/*
class PayKind { // base class - no member variables
public:
	void output(ostream& out) const { out << *this; }

	friend ostream& operator<< (ostream&, const PayKind&);
};
*/

class PerCourse : public PayKind
{
public:
	PerCourse() : PayKind(), _feePerCourse(0) {};
	PerCourse(unsigned iFee) : _feePerCourse(iFee) {};
	~PerCourse() { cout << "Percourse deconstructor called" << endl; }

	unsigned getPerCourse(void) const { return _feePerCourse; }
	void output(ostream &out) const { out << *this; }
	friend ostream& operator<< (ostream&, const PerCourse& m);

  double payAdvice(){return (_feePerCourse/7);}
private:
	unsigned _feePerCourse;

};

ostream& operator<< (ostream& out, const PerCourse& m)
{
	out << "Per course: " << m.getPerCourse() << endl;

	return out;
}

class Adjunct : public Faculty, public PerCourse, protected PartTime
{
public:
	Adjunct();
	Adjunct(string iFirst, string iLast, string iAddress, unsigned iID, string iSSN, string iDepartment, unsigned iFee, unsigned iMax, unsigned iMaxCourses);
	~Adjunct() { cout << "Adjunct deconstructor called" << endl; }

	unsigned getMaxCourses(void) const { return _maxCourses; }
	void output(ostream& out) { out << *this; }
	friend ostream& operator<<(ostream& out, Adjunct& m);


private:
	unsigned _maxCourses;
};

ostream& operator<<(ostream& out, Adjunct& m)
{

	out << "First Name: " << m.getFirstName() << endl;
	out << "Last Name: " << m.getLastName() << endl;
	out << "Address: " << m.getAddress() << endl;
	out << "ID: " << m.get_IDNumber() << endl;
	out << "SSN: " << m.getSSN() << endl;
	out << "Department: " << m.getDepartment() << endl;
	out << "Fee: " << m.getPerCourse() << endl;
	out << "Max hours: " << m.getMax() << endl;
	out << "Max courses: " << m.getMaxCourses() << endl;


	return out;
}

//Faculty(string firstName, string lastName, string address, unsigned _IDNumber, string SSN, string department);
Adjunct::Adjunct(string iFirst, string iLast, string iAddress, unsigned iID, string iSSN, string iDepartment, unsigned iFee, unsigned iMax, unsigned iMaxCourses):
	Faculty(iFirst, iLast, iAddress, iID, iSSN, iDepartment), PerCourse(iFee),  PartTime(iMax)
{
	_maxCourses = iMaxCourses;
}

UMLPerson::UMLPerson(const UMLPerson& p) {
	// make an independent copy of any dynamic member variables of UMLPerson here
	_firstName = p._firstName;
	_lastName = p._lastName;
	_address = p._address;
	_IDNumber_ = p._IDNumber_;
	cout << "UMLPerson copy constructor called for \"" << _firstName << " " << _lastName << "\"\n";
}

UMLPerson::~UMLPerson() {
	// delete any dynamic data members for UMLPerson here
	cout << "UMLPerson destructor called for \"" << _firstName << " " << _lastName << "\"\n";
}

Student::Student(string firstName, string lastName, string address, unsigned _IDNumber,
	double GPA, string smajor, string advisorName)
	: UMLPerson(firstName, lastName, address, _IDNumber)
{
	_GPA = GPA;
	_smajor = smajor;
	_advisorName = advisorName;
}

Student::Student(const Student& s) : UMLPerson(s) {
	// make an independent copy of any dynamic member variables of Student here
	_GPA = s._GPA;
	_smajor = s._smajor;
	_advisorName = s._advisorName;

	cout << "Student copy constructor called for \""
		<< s.getFirstName() << " " << s.getLastName() << "\"\n";
}

Student::~Student() {
	// delete any dynamic data members for Student here
	cout << "Student destructor called for \"" << getFirstName() << " " << getLastName() << "\"\n";
}

Undergrad::Undergrad(string firstName, string lastName, string address, unsigned _IDNumber,
	double GPA, string smajor, string advisorName, string classRank)
	: Student(firstName, lastName, address, _IDNumber, GPA, smajor, advisorName)
{
	_classRank = classRank;
}

Undergrad::Undergrad(const Undergrad& u) : Student(u) {
	// make an independent copy of any dynamic member variables of Student here
	_classRank = u._classRank;

	cout << "Undergrad copy constructor called for \""
		<< u.getFirstName() << " " << u.getLastName() << "\"\n";
}

Undergrad::~Undergrad() {
	// delete any dynamic data members for Student here
	cout << "Undergrad destructor called for \"" << getFirstName() << " " << getLastName() << "\"\n";
}

Grader::Grader(string firstName, string lastName, string address, unsigned _IDNumber,
	double GPA, string smajor, string advisorName, string classRank,
	string classNumber, unsigned hourlyRate, unsigned maxHours)
	: Undergrad(firstName, lastName, address, _IDNumber, GPA, smajor, advisorName, classRank),
	Hourly(hourlyRate), PartTime(maxHours)
{
	_classNumber = classNumber;
}

Grader::Grader(const Grader& g) : Undergrad(g), Hourly(g) {
	// make an independent copy of any dynamic member variables of Student here
	_classNumber = g._classNumber;

	cout << "Grader copy constructor called for \""
		<< g.getFirstName() << " " << g.getLastName() << "\"\n";
}

Grader::~Grader() {
	// delete any dynamic data members for Student here
	cout << "Grader destructor called for \"" << getFirstName() << " " << getLastName() << "\"\n";
}

Employee::Employee(string firstName, string lastName, string address, unsigned _IDNumber,
	string SSN)
	: UMLPerson(firstName, lastName, address, _IDNumber)
{
	_SSN = SSN;
}

Faculty::Faculty(string firstName, string lastName, string address, unsigned _IDNumber,
	string SSN, string department)
	: Employee(firstName, lastName, address, _IDNumber, SSN)
{
	_department = department;
}

NTT::NTT(string firstName, string lastName, string address, unsigned _IDNumber,
	string SSN, string department, string rank, unsigned salary)
	: Faculty(firstName, lastName, address, _IDNumber, SSN, department), Salaried(salary)
{
	_rank = rank;
}

ostream& operator<< (ostream& out, const UMLPerson& p) {
	out << "First Name:\t" << p._firstName << endl
		<< "Last Name:\t" << p._lastName << endl
		<< "Address:\t" << p._address << endl
		<< "ID Number:\t" << p._IDNumber_ << endl;

	return out;
}

ostream& operator<< (ostream& out, const Student& s) {
	s.UMLPerson::output(out); // display the UMLPerson variables

	out << "GPA:\t\t" << s.getGPA() << endl
		<< "Major:\t\t" << s.getSmajor() << endl
		<< "Advisor Name:\t" << s.getAdvisorName() << endl;

	return out;
}

ostream& operator<< (ostream& out, const Undergrad& u) {
	u.Student::output(out); // display the Student variables

	out << "Class Rank:\t" << u.getClassRank() << endl;

	return out;
}

ostream& operator<< (ostream& out, const Grader& u) {
	u.Undergrad::output(out); // display the Student variables

	out << "Class Number:\t" << u.getClassNumber() << endl;

	u.Hourly::output(out); // display the Hourly variables

	return out;
}

ostream& operator<< (ostream& out, const Employee& e) {
	e.UMLPerson::output(out); // display the UMLPerson variables

	out << "SSN:\t\t" << e.getSSN() << endl;

	return out;
}

ostream& operator<< (ostream& out, const Faculty& f) {
	f.Employee::output(out); // display the Employee variables

	out << "Department:\t" << f.getDepartment() << endl;

	return out;
}

ostream& operator<< (ostream& out, const NTT& n) {
	n.Faculty::output(out); // display the Faculty variables

	out << "Rank:\t\t" << n.getRank() << endl;

	n.Salaried::output(out); // display the Salary variables

	return out;
}


int main(void) {
	UMLPerson p;
	cout << "UMLPerson():\n" << p << endl;

	Student s;
	cout << "Student():\n" << s << endl;

	Undergrad u;
	cout << "Undergrad():\n" << u << endl;

	Grader g;
	cout << "Grader():\n" << g << endl;

	Undergrad s1("Sally", "Brown", "110 Canal Street", 12345678, 4.0, "CS", "Tom Wilkes", "senior");
	Undergrad s2("Jimmy", "Smith", "99 Canal Street", 87654321, 3.0, "CS", "Tom Wilkes", "freshman");

	cout << "Undergrad s1(Sally...):\n" << s1 << endl;
	cout << "Undergrad s2(Jimmy...):\n" << s2 << endl;

	Grader g1("John", "Doe", "89 Canal Street", 54329876, 3.5, "CS", "Tom Wilkes", "junior",
		"COMP.2010", 25.00, 30);
	cout << "Grader g1(John...):\n" << g1 << endl;

	Grader g2(g1); // invoke copy constructor
	cout << "Grader g2(copy of g1 - John...):\n" << g2 << endl;

	NTT n1("Tom", "Wilkes", "Foo Street", 52901256, "123-45-6789", "Computer Science", "Assistant Teaching Professor", 12345);
	cout << "NTT Faculty n1(Tom...):\n" << n1 << endl;

	PerCourse p1(1000.00);
	cout << "Fee per course: " << p1 << endl;
	//Adjunct(string iFirst, string iLast, string iAddress, unsigned iID, string iSSN, string iDepartment, unsigned iFee, unsigned iMax, unsigned iMaxCourses);
	Adjunct a1("John", "Doe", "10 road", 0123, "23-456-7891", "Biology", 100, 30, 5);
	cout << a1 << endl;

	cout << "Grader payAdvice()= " << g1.payAdvice() << endl;
	cout << "NTT payAdvice()= " << n1.payAdvice() << endl;
	cout << "Adjunct payAdvice()= " << a1.payAdvice() << endl;

  vector<NTT*> nv;
	nv.push_back(&n1);
	cout << 0 << ":\n" << *nv[0];
	cout << "Pay Advice is " << nv[0]->payAdvice() << endl << endl;
	vector<UMLPerson*> uv;
	uv.push_back(&s1);
	uv.push_back(&s1);
	uv.push_back(&g1);
	uv.push_back(&n1);
	for (int i = 0; i < 4; i++) {
		cout << i << ":\n" << *uv[i] << endl;
	}
	cout << endl;

	return 0;
}
