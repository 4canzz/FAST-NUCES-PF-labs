#include <iostream>
#include <string>

using namespace std;

struct Student {
	string name;
	int rollnumber;
};

void displayStudent(const Student &s) {
	cout << "Name: " << s.name << ", Roll Number: " << s.rollnumber << endl;
}

int main() {
	Student s1;
	s1.name = "Syed Furqan Hassan";
	s1.rollnumber = 6116;
	Student *ptr = &s1;
	cout << "Accessing via pointer: " << endl << "Name: " << ptr -> name << ", Roll Number: " << ptr -> rollnumber << endl;

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
	}

	cout << endl << "Displaying student details: " << endl;
	for (int i = 0; i < n; i++) {
		displayStudent(students[i]);
	}

	delete[] students;
	system("pause");
	return 0;
}


    delete[] students;
    return 0;
}

/*Exercise 2: (10 points)
Using the above example as guideline please define a struct named Student, with two data
members: name and rollnumber .
Write a program that demonstrates the following:
a. Create a Student variable and access its data members. Please use your own name and
rollnumber.
b. Create a Student pointer that carries the address of the variable declared in step a and
access its data members via the pointer.
c. Write a function that takes as parameter the Student variable declared in step a and
displays its data members
d. Create a dynamic array of Students after asking the user about the number of Students
they would like to enter and then uses the function written above in a loop to get data for
the students. Display the data in another loop.*/
