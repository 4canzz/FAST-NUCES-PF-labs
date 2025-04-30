#include <iostream>
using namespace std;

class comp {
private:
    double real;
    double imag;

public:
    comp() {
        real = 0;
        imag = 0;
    }

    void setpara(double r, double i) {
        real = r;
        imag = i;
    }

    void show() const {
        cout << real << " + " << imag << "i" << endl;
    }

    comp operator+(const comp& other) const {
        comp temp;
        temp.real = real + other.real;
        temp.imag = imag + other.imag;
        return temp;
    }

    comp operator-(const comp& other) const {
        comp temp;
        temp.real = real - other.real;
        temp.imag = imag - other.imag;
        return temp;
    }

    comp operator*(const comp& other) const {
        comp temp;
        temp.real = real * other.real - imag * other.imag;
        temp.imag = real * other.imag + imag * other.real;
        return temp;
    }

    comp operator/(const comp& other) const {
        comp temp;
        double denom = other.real * other.real + other.imag * other.imag;
        temp.real = (real * other.real + imag * other.imag) / denom;
        temp.imag = (imag * other.real - real * other.imag) / denom;
        return temp;
    }

    bool operator==(const comp& other) const {
        return (real == other.real && imag == other.imag);
    }

    comp& operator=(const comp& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }
};

int main() {
    comp n1, n2, n3;
    n1.setpara(2, 3);
    n2.setpara(1, 4);
    n3 = n1;
    n3.show();
    (n1 + n2).show();
    n3 = n1 * n2;
    n3.show();
    n3 = n1 - n2;
    n3.show();
    n3 = n1 / n2;
    n3.show();
    if (n1 == n2)
        cout << "Both no have same real and imag part" << endl;
    else
        cout << "Unequal !!!" << endl;

    return 0;
}