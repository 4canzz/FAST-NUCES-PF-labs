//(c) 24L - 6116
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void encode(char buffer[], int key);
void decode(char buffer[], int key);

int main () {
    int key, option;
    char buffer[100000];

    cout << "Text: ";
    cin.getline(buffer, 100001);

    cout << "enter key: ";
    cin >> key;

    cout << "Enter 0 to encrypt the message, and 1 to decrypt the message: ";
    cin >> option;

    do {
        cout << "please enter only 0 or 1: ";
        cin >> option;
    } while (option != 1 && option != 0);

    if (option == 0) {
        encode(buffer, key);
    }
    else if (option == 1) { 
        decode(buffer, key);
    }

    return 0;
}

void encode(char buffer[], int key) {
    cout << "Encrypted Text: ";
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (static_cast<char>(buffer[i] + key) == '#') cout << " ";
        else {
            cout << static_cast<char>(buffer[i] + key);
        }
    }
    cout << ", ";
}

void decode(char buffer[], int key) {
    cout << "Decrypted Text: ";
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (static_cast<char>(buffer[i] - key) == '#') cout << " ";
        else {
            cout << static_cast<char>(buffer[i] - key);
        }
    }
    cout << endl;
}

/*Exercise 3: (10 points)
Encryption can be very useful method for protecting sensitive data from intruders. Data is
converted into meaningless form by the usage of a given key and it is converted back to original
form by utilizing the key again when required. You need to design an encryption\decryption
application.
Example:
Inputs:Text: hello world , Key: 3
Outputs:
Encrypted text: khoor zruog , Decrypted text: hello world
Note:
1. Use only character arrays.
2. String Library functions are not allowed.
3. Make separate functions for encryption and decryption and write down the main
function as well to make the code interactive.
Usage of temporary arrays is prohibited. Both encryption and decryption should be performed*/