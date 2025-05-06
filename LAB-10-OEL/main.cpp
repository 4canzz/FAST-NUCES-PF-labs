//(c) 24L - 6116
#include "manager.h"

int main() {
    StudentManager<int> intManager;
    intManager.loadFromFile("students_int.txt");
    intManager.generateReport("report_int.txt");

    StudentManager<float> floatManager;
    floatManager.loadFromFile("students_float.txt");
    floatManager.generateReport("report_float.txt");

    return 0;
}
