//(c) 24L-6116
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

/*Exercise 1: (15 points)
Design a class named Complex to represent complex numbers. The class should have two private data members of type double:
real — to store the real part of the complex number
imag — to store the imaginary part of the complex number
Implement overloaded operator functions to perform operations on two Complex objects.

1. *(Multiplication)
2. +(Addition)
3. –(Subtraction)
4. /(Division)
5. =(Assignment)
6. == (Equality Comparator – two equal signs without space) The Class definition is given below:

class comp
{
double real; double imag;
public:
//	default constructor
//	function that set real and imag part of complex no
//	function that print complex number
//	Opertator “+” for addition
//	Opertator “-” for Subtraction
//	Opertator “*” for Multiplication
//	Opertator “/” for Division
//	Opertator “==” for check both complex are equal or not
//	Opertator “=” for assignment
};

Your program should run for the following main().
int main()
{
    comp n1,n2,n3;

    n1.setpara(2,3);
    n2.setpara(1,4); n3=n1;

    n3.show();

    (n1+n2).show();
    n3=n1*n2; n3.show();

    n3=n1-n2; n3.show();
    n3=n1/n2; n3.show();

    if(n1==n2)
    cout<<"Both no have same real and imag part "<<endl;
    else
    cout<<"Unequal !!!"<<endl;
    return 0;
}*/