//(c) 24L - 6116
#include <iostream>
#include <string>
using namespace std;

class Bike {
private:
    string brand;
    string model;
    int price;
    int topSpeed;

public:
    Bike();
    Bike(string b, string m, double p, int ts);
    ~Bike();

    void setBrand(string b) {
        brand = b; 
    }
    string getBrand() const {
        return brand; 
    }

    void setModel(string m) { 
        model = m; 
    }
    string getModel() const {
        return model; 
    }

    void setPrice(double p) {
        price = p; 
    }
    double getPrice() const {
        return price; 
    }

    void setTopSpeed(int ts) {
        topSpeed = ts; 
    }
    int getTopSpeed() const {
        return topSpeed; 
    }

    void display() const {
        cout << "Bike Details: " << endl;
        cout << "Brand: " << brand << endl << "Model: " << model << endl <<"Price: $" << price << endl << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};
Bike::Bike() {
    brand = " ";
    model = " ";
    price = 0;
    topSpeed = 0;
}

Bike::Bike(string b, string m, double p, int ts) {
    brand = b;
    model = m;
    price = p;
    topSpeed = ts;
}

Bike::~Bike() {
    cout << "Destructor called for Bike: " << brand << " " << model << endl;
}

void showBikeDetails(const Bike& b) {
    cout << "Displaying Bike from Non-Member Function:" << endl;
    b.display();
}

int main() {
    Bike myBike("Honda", "CD70", 170000, 120);
    myBike.display();

    Bike* bikePtr = new Bike("Honda", "CG125", 200000, 140);
    bikePtr->display();

    bikePtr->setBrand("Yamaha");
    bikePtr->setModel("YBR-125G");
    bikePtr->setPrice(400000);
    bikePtr->setTopSpeed(130);

    cout << endl << "After Modifications:" << endl;
    cout << "Brand: " << bikePtr->getBrand() << endl;
    cout << "Model: " << bikePtr->getModel() << endl;
    cout << "Price: $" << bikePtr->getPrice() << endl;
    cout << "Top Speed: " << bikePtr->getTopSpeed() << " km/h" << endl;

    showBikeDetails(*bikePtr);

    delete bikePtr;

    return 0;
}

/*Exercise 1: (10 points)
Using the above example as guideline please define a class named Bike, with four data members:
brand, model, price and topspeed.
Write a program that includes the following:
a. Default constructor.
b. Parameterized constructor.
c. Destructor.
d. Accessor/Mutator function for every data member.
e. A general member function that displays all the data members .
f. Write a main function that:
a. Create a Bike object and call its various member functions using that object.
b. Create a Bike pointer and calls its various member functions using the pointer.
g. Write a non-member function that takes as parameter the Bike variable declared in
above steps and displays its data members
Please give the screenshot of the output that you get after running your program:*/
