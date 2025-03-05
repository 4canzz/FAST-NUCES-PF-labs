#include <iostream>
#include <string>
using namespace std;

class Bike {
private:
    string brand;
    string model;
    double price;
    int topSpeed;

public:
    Bike() : brand("Unknown"), model("Unknown"), price(0.0), topSpeed(0) {}

    Bike(string b, string m, double p, int ts) : brand(b), model(m), price(p), topSpeed(ts) {}

    ~Bike() {
        cout << "Destructor called for Bike: " << brand << " " << model << endl;
    }

    void setBrand(string b) { brand = b; }
    string getBrand() const { return brand; }

    void setModel(string m) { model = m; }
    string getModel() const { return model; }

    void setPrice(double p) { price = p; }
    double getPrice() const { return price; }

    void setTopSpeed(int ts) { topSpeed = ts; }
    int getTopSpeed() const { return topSpeed; }

    void display() const {
        cout << "Bike Details:\n";
        cout << "Brand: " << brand << "\nModel: " << model << "\nPrice: $" << price << "\nTop Speed: " << topSpeed << " km/h\n";
    }
};

void showBikeDetails(const Bike &b) {
    cout << "Displaying Bike from Non-Member Function:\n";
    b.display();
}

int main() {
    Bike myBike("Yamaha", "R1", 20000, 299);
    myBike.display();

    Bike* bikePtr = new Bike("Honda", "CBR600RR", 12000, 250);
    bikePtr->display();

    bikePtr->setBrand("Suzuki");
    bikePtr->setModel("GSX-R750");
    bikePtr->setPrice(14000);
    bikePtr->setTopSpeed(280);

    cout << "\nAfter Modifications:\n";
    cout << "Brand: " << bikePtr->getBrand() << "\n";
    cout << "Model: " << bikePtr->getModel() << "\n";
    cout << "Price: $" << bikePtr->getPrice() << "\n";
    cout << "Top Speed: " << bikePtr->getTopSpeed() << " km/h\n";

    showBikeDetails(*bikePtr);

    delete bikePtr;

    return 0;
}