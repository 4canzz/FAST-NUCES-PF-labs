//(c) 24L - 6116
#include <iostream>
#include <string>
using namespace std;

template<typename var>
class point{
public:
	point();
	point(var value_x, var value_y);
	var get_x() const;
	var get_y() const;
	void print() const;
	void move(var dx, var dy);
private:
	var x, y;
};

template<typename var>
point<var>::point(){
	x = 0.0; y = 0.0;
}

template<typename var>
point<var>::point(var a, var b){
	x = a; y = b;
}

template<typename var>
void point<var>::print() const{
	cout << x << " " << y << endl;
}

template<typename var>
var point<var>::get_x() const{
	return x;
}

template<typename var>
var point<var>::get_y() const{
	return y;
}

template<typename var>
void point<var>::move(var dx, var dy){
	x = x + dx;
	y = y + dy;
}

int main()
{
	point<int> A = point<int>(1, 2);
	A.print();
	A.move(4, -5);
	A.print();

	point<float>B(3.2, 4.9);
	cout << B.get_x() << " " << B.get_y() << endl;
	point<string> C("day", "young");
	C.print();
	C.move("s", "ster");
	C.print();

	system("pause");
	return 0;
}

/*Exercise 3: (10 points)
Consider the class of points in the xy plane. The location of each point is determined by the real numbers (x, y) specifying the 
cartesian coordinates. 

The class definition is:

#include<iostream>
using namespace std;
class point{
public:
	point();
	point(double value_x, double value_y);
	doubleget_x() const;
	doubleget_y() const;
	void print() const;
	void move(double dx, doubledy);
private:
	double x, y;
};
point::point(){
	x = 0.0; y = 0.0;
}
point::point(double a, double b){
	x = a; y = b;
}
void point::print() const{
	cout<<x<<""<<y<<endl;
}
double point::get_x() const{
	return x;
}
double point::get_y() const{
	return y;
}
void point::move(double dx, doubledy){
	x = x+dx;
	y = y+dy;
}

Generalize the class Point into a template and test your code using following main function.
int main()
{
	point<int> A = point<int>(1, 2);
	A.print();
	A.move(4, -5);
	A.print();

	point<float>B(3.2, 4.9);
	cout<<B.get_x() <<""<<B.get_y() <<endl ;
	point<string> C("day", "young");
	C.print();
	C.move("s","ster");
	C.print();
return 0; 
}*/
