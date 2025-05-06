/**
 * RENTAL SYSTEM HEADER FILE
 * CS1002
 * Programming Fundamentals - Assignment 3
 * Syed Furqan Hassan
 * 24L - 6116
 * BEE - 2D
 **/

 #pragma once
 #include <iostream>
 #include <string>
 #include "List.h"
 #include "Vehicles.h"
 #include "Customer.h"
 #include "RentalTransaction.h"
 using namespace std;

 class RentalSystem {
 private:
     List<Vehicle*>* vehicles;
     List<Customer*>* customers;
     List<RentalTransaction*>* transactions;

 public:
     RentalSystem(int vmax, int cmax, int tmax) {
         vehicles = new List<Vehicle*>(vmax);
         customers = new List<Customer*>(cmax);
         transactions = new List<RentalTransaction*>(tmax);
     }

     ~RentalSystem() {
        for (int i = 0; i < vehicles->getCount(); ++i)
            delete (*vehicles)[i];
        for (int i = 0; i < customers->getCount(); ++i)
            delete (*customers)[i];
        for (int i = 0; i < transactions->getCount(); ++i)
            delete (*transactions)[i];

        delete vehicles;
        delete customers;
        delete transactions;
    }

     void addVehicle(const Vehicle& vehicle) {
         if (vehicle.getType() == "Car") {
             vehicles->add(new Car(vehicle));
         } else if (vehicle.getType() == "Truck") {
             vehicles->add(new Truck(vehicle));
         }
     }

     void addCustomer(const Customer& customer) {
         customers->add(new Customer(customer));
     }

     void rentVehicle(const string& customerId, const string& vehicleId, const Date& startDate, const Date& endDate) {
         Customer* customer = nullptr;
         Vehicle* vehicle = nullptr;

         for (int i = 0; i < customers->getCount(); i++) {
             if ((*customers)[i]->getCNIC() == customerId) {
                 customer = (*customers)[i];
                 break;
             }
         }

         for (int i = 0; i < vehicles->getCount(); i++) {
             if ((*vehicles)[i]->getModel() == vehicleId && (*vehicles)[i]->getAvailability()) {
                 vehicle = (*vehicles)[i];
                 break;
             }
         }

         if (customer && vehicle) {
            int days = endDate - startDate;
            if (days <= 0) {
                cout << "Invalid rental period." << endl;
                return;
            }
            RentalTransaction* transaction = new RentalTransaction(customer, vehicle, startDate, endDate, days);
            transactions->add(transaction);
         } else {
             cout << "Customer or Vehicle not found or Vehicle not available." << endl;
         }
     }

     void returnVehicle(const string& vehicleId) {
         for (int i = 0; i < transactions->getCount(); i++) {
             if ((*transactions)[i]->getVehicle()->getModel() == vehicleId && (*transactions)[i]->getIsActive()) {
                 (*transactions)[i]->completeTransaction();
                 cout << "Vehicle returned successfully." << endl;
                 return;
             }
         }
         cout << "Transaction not found or Vehicle already returned." << endl;
     }

     void displayCustomerRentalHistory(const string& customerId) const {
         bool found = false;
         for (int i = 0; i < transactions->getCount(); i++) {
             if ((*transactions)[i]->getCustomer()->getCNIC() == customerId) {
                 cout << *(*transactions)[i] << endl;
                 found = true;
             }
         }
         if (!found) {
             cout << "No rental history found for CNIC: " << customerId << endl;
         }
     }

     void searchVehicleByModel(const string& model) const {
         bool found = false;
         for (int i = 0; i < vehicles->getCount(); ++i) {
             if ((*vehicles)[i]->getModel() == model) {
                 cout << *(*vehicles)[i] << endl;
                 found = true;
             }
         }
         if (!found) {
             cout << "No vehicles found with model: " << model << endl;
         }
     }

     void filterVehiclesByPriceRange(double minPrice, double maxPrice) const {
         bool found = false;
         for (int i = 0; i < vehicles->getCount(); ++i) {
             double price = (*vehicles)[i]->getPricePerDay();
             if (price >= minPrice && price <= maxPrice) {
                 cout << *(*vehicles)[i] << endl;
                 found = true;
             }
         }
         if (!found) {
             cout << "No vehicles found in price range $" << minPrice << " - $" << maxPrice << endl;
         }
     }

     void displayAvailableVehicles() const {
         for (int i = 0; i < vehicles->getCount(); i++) {
             if ((*vehicles)[i]->getAvailability()) {
                 cout << *(*vehicles)[i] << endl;
             }
         }
     }

     void displayRentedVehicles() const {
         for (int i = 0; i < vehicles->getCount(); i++) {
             if (!(*vehicles)[i]->getAvailability()) {
                 cout << *(*vehicles)[i] << endl;
             }
         }
     }

     void displayCustomers() const {
         for (int i = 0; i < customers->getCount(); i++) {
             cout << *(*customers)[i] << endl;
         }
     }
 };
