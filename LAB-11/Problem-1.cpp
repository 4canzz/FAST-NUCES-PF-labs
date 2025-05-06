//(c) 24L - 6116
#include <iostream>
using namespace std;

class Employee {
protected:
	int employeeid;
	double basicSalary;
public:
	Employee(int id, double s) {
		employeeid = id;
		basicSalary = s;
	}

	virtual double calculateSalary() const = 0;
	virtual void display() const {
		cout << "Employee ID: " << employeeid << endl;
		cout << "Basic Salary: " << basicSalary << endl;
	}

	virtual ~Employee() {}
};

class CommissionedEmployee : public Employee {
	double salesamount;
	double commissionrate;
public:
	CommissionedEmployee(int id, double salary, double sales, double rate) : Employee(id, salary), salesamount(sales), commissionrate(rate) {}

	double calculateSalary() const override {
		return basicSalary + (salesamount * commissionrate / 100.0);
	}

	void display() const override {
		Employee::display();
		cout << "Sales Amount: " << salesamount << endl;
		cout << "Commission Rate: " << commissionrate << "%" << endl;
		cout << "Total Salary: " << calculateSalary() << " ";
	}
};


class HourlyEmployee : public Employee {
	double payPerHour;
	int extraHours;
public:
	HourlyEmployee(int id, double salary, double rate, int hours) : Employee(id, salary), payPerHour(rate), extraHours(hours) {}

	double calculateSalary() const override {
		return basicSalary + (payPerHour * extraHours);
	}

	void display() const override {
		Employee::display(); 
		cout << "Pay Per Hour: " << payPerHour << endl;
		cout << "Extra Hours: " << extraHours << endl;
		cout << "Total Salary: " << calculateSalary() << "  ";
	}
};

class RegularEmployee : public Employee {
	double bonus;
public:
	RegularEmployee(int id, double salary, double bonusAmount)
		: Employee(id, salary), bonus(bonusAmount) {}

	double calculateSalary() const override {
		return basicSalary + bonus;
	}

	void display() const override {
		Employee::display();
		cout << "Bonus: " << bonus << endl;
		cout << "Total Salary: " << calculateSalary() << "\n\n";
	}
};

int main() {
	CommissionedEmployee E1(25, 5000, 1000, 10);
	// CASE 1 - derived Class Pointer pointing to Derived class object 
	CommissionedEmployee * ptr;
	ptr = &E1;
	cout << "Commissioned Employee salary : " << ptr -> calculateSalary();
	cout << endl;
	// CASE 2 - Base Class Pointer pointing to Derived class object 
	Employee * eptr;
	eptr = &E1;
	cout << "Commissioned Employee salary : " << eptr -> calculateSalary();
	cout << endl;
	CommissionedEmployee E2(25, 5000, 1000, 10);
	CommissionedEmployee E3(26, 5000, 2000, 10);
	HourlyEmployee H1(27, 5000, 10, 100);
	HourlyEmployee H2(28, 5000, 5, 100);
	RegularEmployee R1(29, 5000, 1000);
	RegularEmployee R2(29, 5000, 2000);
	Employee * list[6];
	list[0] = &E2;
	list[1] = &E3;
	list[2] = &H1;
	list[3] = &H2;
	list[4] = &R1;
	list[5] = &R2;
	for (int i = 0; i < 6; i++)
	{
		cout << "Employee " << i << " salary is : " << list[i] -> calculateSalary();
		cout << endl;
	}
	system("pause");
	return 0;
}

/*Exercise 11: (15 points)
We want to design a system for a company to calculate salaries of different types of employees.

Every employee has an employee ID and a basic salary. The Commissioned employee has a sales amount and rate. Hourly employee is paid
on the basis of number of working hours. A regular employee may have a bonus. 

You have to implement all the above classes. Write constructor for all classes. The main functionality is to calculate salary for
each employee which is calculated as follows:

Commissioned Employee: 		Total Salary = sales amount * rate / 100 + basic salary
Hourly Employee: 			Total salary = basic salary + pay per hour * extra hours
Regular Employee:			Total salary = basic salary + bonus


Use the following main().

int  main() 
{    
	CommissionedEmployee  E1(25, 5000, 1000, 10); 

// CASE 1 - derived Class Pointer pointing to Derived class object 

	CommissionedEmployee * ptr;  
	ptr = &E1;  
	cout<<" Commissioned Employee salary:"<<ptr->calculateSalary();
	cout<<endl;       

// CASE 2 - Base Class Pointer pointing to Derived class object 

    Employee * eptr;  
	eptr = &E1;  
	cout<<" Commissioned Employee salary:"<<eptr->calculateSalary();       
	cout<<endl;

	CommissionedEmployee E2 (25, 5000, 1000, 10); 
	CommissionedEmployee E3 (26, 5000, 2000, 10); 

	HourlyEmployeeH1(27, 5000, 10, 100 ); 
	HourlyEmployeeH2(28, 5000, 5, 100 ); 

	RegularEmployeeR1(29, 5000, 1000 );  
	RegularEmployeeR2(29, 5000, 2000 ); 

    Employee * list [6];  
	list[0] = & E2;  
	list[1] = & E3;   
	list[2] = & H1; 
	list[3] = & H2; 
	list[4] = & R1;  
	list[5] = & R2;   

	for(int i = 0 ; i < 6; i++)  
	{ 
		cout<<"Employee "<<i<<" salary is : "<<list[i]->calculateSalary();
		cout<<endl; 
	}   

	return 0; 
}*/