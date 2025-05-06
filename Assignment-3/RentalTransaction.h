/**
 * TRANSACTION HEADER FILE
 * CS1002
 * Programming Fundamentals - Assignment 3
 * Syed Furqan Hassan
 * 24L - 6116
 * BEE - 2D
 **/

#pragma once
#include <iostream>
#include "Customer.h"
#include "Vehicles.h"
#include "List.h"
using namespace std;

struct Date {
    int month, day, year;

    bool isLeap(int y) const { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }
    int daysInMonth(int m, int y) const {
        const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && isLeap(y)) return 29;
        return days[m - 1];
    }

    int toDays() const {
        int days = 0;
        for (int y = 0; y < year; y++) {
            if (isLeap(y)) days+= 366;
            else days += 365;
        }

        for (int m = 1; m < month; m++) {
            days += daysInMonth(m, year);
        }

        days += day;
        return days;
    }

    int operator-(const Date& other) const { return this->toDays() - other.toDays(); }
    friend ostream& operator<<(ostream& os, Date& date);
    friend istream& operator>>(istream& is, const Date& date);
};

class RentalTransaction {
private:
    Customer* customer;
    Vehicle* vehicle;
    Date startDate;
    Date endDate;
    double TotalCost;
    bool isActive;
public:
    RentalTransaction(Customer* c, Vehicle* v, Date start, Date end, int days)
      : customer(c), vehicle(v), startDate(start), endDate(end), isActive(true) {
        TotalCost = v->calculatePrice(days);
        vehicle->setAvailability(false);
    }

    Customer* getCustomer() const { return customer; }
    Vehicle* getVehicle() const { return vehicle; }
    double getCost() const { return TotalCost; }
    Date getStartDate() const { return startDate; }
    Date getEndDate() const { return endDate; }
    bool getIsActive() const { return isActive; }
    void completeTransaction() {
        if (!isActive) return;
        isActive = false;
        vehicle->setAvailability(true);
    }
    friend ostream& operator<<(ostream& os, const RentalTransaction& RT);
};

istream& operator>>(istream& is, Date&  date) {
    cout << "Enter day: ";
    is >> date.day;
    cout << "Enter month: ";
    is >> date.month;
    cout << "Enter year: ";
    is >> date.year;
    return is;
}


ostream& operator<<(ostream& os,const Date& date) {
    os << "Date: " << date.day << "/" << date.month << "/" << date.year;
    return os;
}

ostream& operator<<(ostream& os, const RentalTransaction& RT) {
    os << "Customer: "<< RT.customer->getName() << endl
       << "Vehicle: " << RT.vehicle->getModel() << endl
       << "Cost: $" << RT.TotalCost << endl
       << "Starting Date: " << RT.startDate << endl
       << "Ending Date: " << RT.endDate << endl
       << "Active ?: ";
    if (RT.getIsActive()) os << "Yes";
    else os << "No";
    return os;
}
