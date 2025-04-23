#include <iostream>
#include <string>
using namespace std;

template<typename var>
var myMax(var one, var two)
{
	var bigger;
	if (one < two)
		bigger = two;
	else
		bigger = one;
	return bigger;
}

int main()
{
    int i_one = 3, i_two = 5;
	cout << "The max of " << i_one << " and " << i_two << " is "<< myMax<int>(i_one, i_two) << endl;

	float f_one = 3.14, f_two = 5.5;
	cout << "The max of " << f_one << " and " << f_two << " is " << myMax<float>(f_one, f_two) << endl;

	string s_one = "public static void main (String[] args)", s_two = "int main (int argc, char* argv[])";
	cout << "The max of \"" << s_one << "\" and \"" << s_two << "\" is  \"" << myMax<string>(s_one, s_two) << "\" " << endl;
	system("pause");
	return 0;
}
