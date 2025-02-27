#include <iostream>
#include <string>

using namespace std;

struct Date {
	int day, month, year;
};

struct Student {
	string name;
	int rollnumber;
	Date date_of_birth;
};

void displayStudent(const Student &s) {
		cout << "Name: " << s.name << ", Roll Number: " << s.rollnumber << ", DOB: " << s.date_of_birth.day << "/" << s.date_of_birth.month << "/" << s.date_of_birth.year << endl;
}

int main() {
	Student s1;
	s1.name = "Syed Furqan Hassan";
	s1.rollnumber = 6116;
	s1.date_of_birth.day = 19; s1.date_of_birth.month = 1; s1.date_of_birth.year = 2006;
	Student *ptr = &s1;
	cout << "Accessing via pointer: " << endl << "Name: " << ptr->name << ", Roll Number: " << ptr->rollnumber;
	cout << ", DOB: " << ptr->date_of_birth.day << "/" << ptr->date_of_birth.month << "/" << ptr -> date_of_birth.year << endl;

	displayStudent(s1);

	int n;
	cout << "Enter the number of students: ";
	cin >> n;
	Student *students = new Student[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter name for student " << i + 1 << ": ";
		cin.ignore();
		getline(cin, students[i].name);
		cout << "Enter roll number: ";
		cin >> students[i].rollnumber;
		cout << "Enter date of birth: ";
		cin >> students[i].date_of_birth.day >> students[i].date_of_birth.month >> students[i].date_of_birth.year;
	}

	cout << endl << "Displaying student details: " << endl;
	for (int i = 0; i < n; i++) {
		displayStudent(students[i]);
	}

	delete[] students;
	return 0;
}

/*A. Please declare a struct called Date which should carry 3 integer data members called day,
month and year.
B. Now for the Student struct you declared in exercise1, add date_of_birth data member
whose datatype would be Date.
C. Please demonstrate setting and then displaying values for the date of birth of a Student
variable. You may reuse the code you wrote for exercise1.*/
