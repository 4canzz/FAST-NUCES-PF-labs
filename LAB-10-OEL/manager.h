#pragma once
#include "student.h"
#include <fstream>
#include <sstream>
using namespace std;

template <typename NumericType>
class StudentManager {
    Student<NumericType>** students;
    int capacity;
    int count;

    void resizeArray() {
        int newCapacity;
        if (capacity != 0) {
            newCapacity = capacity * 2;
        } else {
            newCapacity = 1;
        }

        Student<NumericType>** newArray = new Student<NumericType>*[newCapacity];

        for(unsigned int i = 0; i < count; i++) {
            newArray[i] = students[i];
        }

        delete[] students;
        students = newArray;
        capacity = newCapacity;
    }

public:
    StudentManager() : students(nullptr), capacity(0), count(0) {}

    ~StudentManager() {
        for(int i = 0; i < count; i++) {
            delete students[i];
        }
        delete[] students;
    }

    void addStudent(Student<NumericType>* student) {
        if(count >= capacity) resizeArray();
        students[count++] = student;
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);

        string courseType, firstName, lastName;
        while (file >> courseType >> firstName >> lastName) {
            NumericType grades[6];

            if (courseType == "English") {
                for (int i = 0; i < 4; i++) {
                    file >> grades[i];
                    if (grades[i] < 0 || grades[i] > 100) return;
                }
                auto* student = new EnglishStudent<NumericType>(grades[0], grades[1], grades[2], grades[3]);
                student->setName(firstName, lastName);
                addStudent(student);
            }
            else if (courseType == "History") {
                for (int i = 0; i < 3; i++) {
                    file >> grades[i];
                    if (grades[i] < 0 || grades[i] > 100) return;
                }
                auto* student = new HistoryStudent<NumericType>(grades[0], grades[1], grades[2]);
                student->setName(firstName, lastName);
                addStudent(student);
            }
            else if (courseType == "Math") {
                for (int i = 0; i < 6; i++) {
                    file >> grades[i];
                    if (grades[i] < 0 || grades[i] > 100) return;
                }
                auto* student = new MathStudent<NumericType>(
                    grades[0], grades[1], grades[2], grades[3], grades[4], grades[5]
                );
                student->setName(firstName, lastName);
                addStudent(student);
            }
        }
    }


    void generateReport(const string& filename) {
        ofstream outFile(filename);
        for(unsigned int i = 0; i < count; i++) {
            students[i]->printReport(outFile);
            outFile << "------------------------\n";
        }
    }
};
