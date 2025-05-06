/**
 * VEHICLE HEADER FILE
 * CS1002
 * Programming Fundamentals - Assignment 3
 * Syed Furqan Hassan
 * 24L - 6116
 * BEE - 2D
 **/

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string model;
    int year;
    double pricePerDay;
    bool available;
public:
    Vehicle(string m = "Unknown", int y = -1, double p = 0.0) : model(m), year(y), pricePerDay(p), available(true) {}
    virtual ~Vehicle() {}

    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPricePerDay() const { return pricePerDay; }
    bool getAvailability() const { return available; }
    void setAvailability(bool status) { available = status; }

    virtual double calculatePrice(int days) const = 0;
    virtual string getType() const = 0;

    bool operator==(const Vehicle& other) const { return (model == other.model && year == other.year); }
    bool operator!=(const Vehicle& other) const { return !(*this == other); }
    friend ostream& operator<<(ostream& os, const Vehicle& vehicle);
};

class Car : public Vehicle {
public:
    Car(string m, int y, double p) : Vehicle(m, y, p) {}
    Car(const Vehicle& v) : Vehicle(v.getModel(), v.getYear(), v.getPricePerDay()) {}

    double calculatePrice(int days) const override { return pricePerDay * days; }
    string getType() const override { return "Car"; }
};

class Truck : public Vehicle {
public:
    Truck(string m, int y, double p) : Vehicle(m, y, p) {}
    Truck(const Vehicle& v) : Vehicle(v.getModel(), v.getYear(), v.getPricePerDay()) {}

    double calculatePrice(int days) const override { return (pricePerDay * days) * 1.05; }
    string getType() const override { return "Truck"; }
};

ostream& operator<<(ostream& os, const Vehicle& vehicle) {
	os << "Vehicle Type: " << vehicle.getType() << endl
       << "Vehicle Model: " << vehicle.model << endl
       << "Vehicle Year: " << vehicle.year << endl
       << "Price Per day: $" << vehicle.pricePerDay << endl
       << "Availabilty status: ";
    if (vehicle.available) os << "Yes";
    else os << "No";
	return os;
}


