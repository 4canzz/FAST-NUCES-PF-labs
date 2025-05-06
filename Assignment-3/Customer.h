/**
 * CUSTOMER HEADER FILE
 * CS1002
 * Programming Fundamentals - Assignment 3
 * Syed Furqan Hassan
 * 24L - 6116
 * BEE - 2D
 **/

#pragma once
#include <iostream>
#include <string>

class Customer {
private:
    string name;
    string cnic;
    string mobileNumber;
public:
    Customer(string n = "", string c = "", string m = "") : name(n), cnic(c), mobileNumber(m) {}
    string getCNIC() const { return cnic; }
    string getName() const { return name; }
    string getMobile() const { return mobileNumber; }

    friend istream& operator>>(istream& is, Customer& customer);
    friend ostream& operator<<(ostream& os, const Customer& customer);
    bool operator==(const Customer& other) const { return cnic == other.cnic; }
    bool operator!=(const Customer& other) const { return !(*this == other); }
};

istream& operator>>(istream& is, Customer& customer) {
    cout << "Enter customer name: ";
    is.ignore();
    getline(is, customer.name);
    cout << "Enter CNIC: ";
    getline(is, customer.cnic);
    cout << "Enter mobile number: ";
    getline(is, customer.mobileNumber);
    return is;
}


ostream& operator<<(ostream& os, const Customer& customer) {
	os << "Name: " << customer.name << endl
       << "CNIC: " << customer.cnic << endl
       << "Mobile: " << customer.mobileNumber;
	return os;
}
