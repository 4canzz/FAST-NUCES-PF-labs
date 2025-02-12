#include <iostream>
#include <cstring>
using namespace std;

char * ReverseSentence(char input[]) {
    char * rev = new char[strlen(input)-1];
    for (int i = 0; i < strlen(input)-1 / 2; i++ ) {
        rev[i] = input[strlen(input)-1-i];
    }
    return rev;
}

int main()
{
    char input[100];
    cin.getline(input,100);
    //For example, user enters National library.
    char *rev = ReverseSentence(input);
    cout << rev << endl;
    // The data pointed to by rev should be yrarbil lanoitaN.
    delete [] rev;
    return 0;
}

/*Exercise 3: (10 points)
Consider following main function and implement the ReverseSentence function
void main()
{
char input[100];
cin.getline(input,100);
//For example, user enters National library.
char *rev=ReverseSentence(input);
cout&lt;&lt;rev&lt;&lt;endl;
// The data pointed to by rev should be yrarbil lanoitaN.
delete [] rev;
}
The length of the character array pointed to by rev should be as per the size of the sentence
entered by the user.
In the space below please give the screenshot of the output you get after running your code*/