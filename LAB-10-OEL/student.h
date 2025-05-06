//(c) 24L - 6116
#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

template <typename NumericType>
class Student {
protected:
    string firstName;
    string lastName;

public:
    virtual ~Student() = default;
    virtual NumericType calculateGrade() const = 0;
    virtual void printReport(ostream& os) const = 0;

    void setName(const string& first, const string& last) {
        firstName = first;
        lastName = last;
    }
};

template <typename NumericType>
class EnglishStudent : public Student<NumericType> {
private:
    NumericType attendance;
    NumericType project;
    NumericType midterm;
    NumericType finalExam;
public:
    EnglishStudent(NumericType a, NumericType p, NumericType m, NumericType f) : attendance(a), project(p), midterm(m), finalExam(f) {}

    NumericType calculateGrade() const override {
        return (attendance*0.1) + (project*0.3) + (midterm*0.3) + (finalExam*0.3);
    }

    void printReport(ostream& os) const override {
        os << "ENGLISH STUDENT: " << this->firstName << " " << this->lastName << endl;
        os << "  Attendance: " << attendance << endl;
        os << "  Project: " << project << endl;
        os << "  Midterm: " << midterm << endl;
        os << "  Final Exam: " << finalExam << endl;
        os << "  Final Grade: " << this->calculateGrade() << endl;
    }
};

template <typename NumericType>
class HistoryStudent : public Student<NumericType> {
private:
    NumericType termPaper;
    NumericType midterm;
    NumericType finalExam;
public:
    HistoryStudent(NumericType tp, NumericType m, NumericType f) : termPaper(tp), midterm(m), finalExam(f) {}

    NumericType calculateGrade() const override {
        return (termPaper*0.25) + (midterm*0.35) + (finalExam*0.4);
    }

    void printReport(ostream& os) const override {
        os << "HISTORY STUDENT: " << this->firstName << " " << this->lastName << endl;
        os << "  Term Paper: " << termPaper << endl;
        os << "  Midterm: " << midterm << endl;
        os << "  Final Exam: " << finalExam << endl;
        os << "  Final Grade: " << this->calculateGrade() << endl;;
    }
};

template <typename NumericType>
class MathStudent : public Student<NumericType> {
private:
    NumericType quiz1;
    NumericType quiz2;
    NumericType quiz3;
    NumericType test1;
    NumericType test2;
    NumericType finalExam;
public:
    MathStudent(NumericType q1, NumericType q2, NumericType q3, NumericType t1, NumericType t2, NumericType f) : quiz1(q1), quiz2(q2), quiz3(q3), test1(t1), test2(t2), finalExam(f) {}

    NumericType calculateGrade() const override {
        NumericType quizAvg = (quiz1 + quiz2 + quiz3) / 3.0;
        return (quizAvg*0.1) + (test1*0.25) + (test2*0.25) + (finalExam*0.4);
    }

    void printReport(ostream& os) const override {
        os << "MATH STUDENT: " << this->firstName << " " << this->lastName << endl;
        os << "  Quizzes: " << quiz1 << ", " << quiz2 << ", " << quiz3 << endl;
        os << "  Test 1: " << test1 << endl;
        os << "  Test 2: " << test2 << endl;
        os << "  Final Exam: " << finalExam << endl;
        os << "  Final Grade: " << this->calculateGrade() << endl;;
    }
};
