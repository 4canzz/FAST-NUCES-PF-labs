//(c) 24L - 6065
#include <iostream>
#include <string>
using namespace std;

class PointType {
private:
    int x;
    int y;
public:
    PointType() : x(0), y(0) {}
    PointType(int a, int b) : x(a), y(b) {}
    void print() const {
        cout << "(" << x << "," << y << ")" << endl;
    }
    void checkQuad() const {
        if (x == 0 && y == 0) {
        cout << "Point is at the origin" << endl;
        }
        else if (x == 0) {
            cout << "Point lies on the y-axis" << endl;
        }
        else if (y == 0) {
            cout << "Point lies on the x-axis" << endl;
        }
        else if (x > 0 && y > 0) {
            cout << "1st quadrant" << endl;
        }
        else if (x > 0 && y < 0) {
            cout << "4th quadrant" << endl;
        }
        else if (x < 0 && y < 0) {
            cout << "3rd quadrant" << endl;
        }
        else if (x < 0 && y > 0) {
            cout << "2nd quadrant" << endl;
        }
    }
};

class CircleType {
private:
    double radius;
    string color;
    PointType center;
public:
    CircleType() : radius(0) {}
    CircleType(double r, string c, PointType cr) : radius(r), color(c), center(cr) {}
        void print() const {
        cout << "Center: ";
        center.print();
        cout << "Radius: " << radius << endl;
        cout << "Color: " << color << endl;
    }
    void printArea() const {
        if (radius <= 0) {
            cout << "Invalid radius" << endl;
            return;
        }
        double a = 3.14 * radius * radius;
        cout << "Area: " << a << endl;
    }
    void printCircumference() const {
        if (radius <= 0) {
            cout << "Invalid radius" << endl;
            return;
        }
        double cf = 2 * 3.14 * radius;
        cout << "Circumference: " << cf << endl;
    }
};

int main() {
    PointType pt(2, 3);
    CircleType C(21, "blue", pt);
    cout << "\n************************\n" << endl;
    C.print();
    cout << "\n************************\n" << endl;
    C.printArea();
    cout << "\n\n************************\n\n" << endl;
    PointType P(-20, 3);
    P.checkQuad();
    P.print();
    double r = 0.0;
    int x = 0, y = 0;
    string col = "";
    cout << "\nEnter radius: ";
    while (!(cin >> r) || r <= 0) {
    cin.clear();
    cin.ignore();
    cout << "Invalid input. Please enter a positive number for radius: ";
    }
    cout << "\nEnter the coordinates where the center lies (x y): ";
    while (!(cin >> x >> y)) {
    cin.clear();
    cin.ignore();
    cout << "Invalid input. Please enter two integers for the coordinates: ";
    }
    cout << "\nEnter color: ";
    cin.ignore();
    getline(cin, col);
    CircleType circ(r, col, PointType(x, y));
    cout << "\n\n***********************\n\n";
    circ.print();
    circ.printArea();
    circ.printCircumference();
    cout << "\n\n***********************\n\n";
    return 0;
}

/*Exercise 1: (15 points)
Create two classes DM and DB that store the value of distances. DM stores distance in meters and centimeters and DB converts them
to feet and inches.

Write a program that can read values for the class objects and converts them. Use a friend function to carry out the conversion
operation by getting values from the user. The object that stores the results should be a DB object, depending on the units in which
the results are required. The display should be in the format of feet and inches.*/