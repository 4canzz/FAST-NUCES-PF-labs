/**
 * IMPLMENTATION FILE
 * CS1002
 * Programming Fundamentals - Assignment 3
 * Syed Furqan Hassan
 * 24L - 6116
 * BEE - 2D
 **/

#include <iostream>
#include <string>
#include "RentalSystem.h"
using namespace std;

void displayMenu() {
    cout << endl << "==============================" << endl;
    cout << "Welcome to the Vehicle Rental System!" << endl;
    cout << "1. Add a customer" << endl;
    cout << "2. Rent a vehicle" << endl;
    cout << "3. Return a vehicle" << endl;
    cout << "4. Display customer rental history" << endl;
    cout << "5. Display available vehicles" << endl;
    cout << "6. Display rented vehicles" << endl;
    cout << "7. Search vehicle by model" << endl;
    cout << "8. Filter vehicles by price range" << endl;
    cout << "9. Exit" << endl;
    cout << "==============================" << endl;
    cout << "Choose an option: ";
}

int main() {
    RentalSystem System(5, 5, 5);
    System.addVehicle(Car("Toyota Corolla", 2020, 50));
    System.addVehicle(Car("Honda Civic", 2019, 45));
    System.addVehicle(Car("Apollo IE", 2023, 4500));
    System.addVehicle(Truck("Ford F-150", 2021, 100));
    System.addVehicle(Truck("Chevrolet Silverado", 2022, 120));

    while (true) {
        displayMenu();

        int choice;
        cin >> choice;
        while (choice <= 0 || choice > 9) {
            cout << "Invalid choice, Please input values 1 - 9: ";
            cin >> choice;
        }

        if (choice == 1) {
            Customer customer;
            cin >> customer;
            System.addCustomer(customer);
        } else if (choice == 2) {
            string customerId, vehicleId;
            Date startDate, endDate;

            cout << "Enter customer CNIC: ";
            cin.ignore();
            getline(cin, customerId);
            cout << "Enter vehicle model: ";
            getline(cin, vehicleId);
            cout << "Enter rental start date (day >> month >> year): ";
            cin >> startDate;
            cout << "Enter rental end date (day >> month >> year): ";
            cin >> endDate;

            System.rentVehicle(customerId, vehicleId, startDate, endDate);
        } else if (choice == 3) {
            string vehicleId;
            cout << "Enter vehicle model to return: ";
            cin.ignore();
            getline(cin, vehicleId);
            System.returnVehicle(vehicleId);
        } else if (choice == 4) {
            string customerId;
            cout << "Enter customer CNIC: ";
            cin.ignore();
            getline(cin, customerId);
            System.displayCustomerRentalHistory(customerId);
        } else if (choice == 5) {
            System.displayAvailableVehicles();
        } else if (choice == 6) {
            System.displayRentedVehicles();
        } else if (choice == 7) {
            string model;
            cout << "Enter vehicle model to search: ";
            cin.ignore();
            getline(cin, model);
            System.searchVehicleByModel(model);
        } else if (choice == 8) {
            double minPrice, maxPrice;
            cout << "Enter minimum price: ";
            cin >> minPrice;
            cout << "Enter maximum price: ";
            cin >> maxPrice;
            System.filterVehiclesByPriceRange(minPrice, maxPrice);
        } else if (choice == 10) {
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}

