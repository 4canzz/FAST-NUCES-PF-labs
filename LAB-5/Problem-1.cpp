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
    Student s1 = {"Syed Furqan Hassan", 12345};
    Student *ptr = &s1;
    cout << "Accessing via pointer: Name: " << ptr->name << ", Roll Number: " << ptr->rollnumber << endl;

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

    cout << "\nDisplaying student details:\n";
    for (int i = 0; i < n; i++) {
        displayStudent(students[i]);
    }

    delete[] students;
    return 0;
}