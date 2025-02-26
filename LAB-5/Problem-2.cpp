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
    cout << "Name: " << s.name << ", Roll Number: " << s.rollnumber
         << ", DOB: " << s.date_of_birth.day << "/" << s.date_of_birth.month
         << "/" << s.date_of_birth.year << endl;
}

int main() {
    Student s1 = {"Syed Furqan Hassan", 12345, {26, 2, 2006}};
    displayStudent(s1);

    return 0;
}