// 24UAM310-Car Rental System.
#include <iostream>
#include <vector>
using namespace std;

// Base Vehicle class
class Vehicle {
protected:
    string vehicleID, make, model;
    int year;
    bool isRented;
    double dailyRentalRate;

public:
    Vehicle(string v_id, string v_make, string v_model, int v_year, double v_rate)
        : vehicleID(v_id), make(v_make), model(v_model), year(v_year), isRented(false), dailyRentalRate(v_rate) {}

    bool getRentalStatus() { return isRented; }
    string getVehicleID() { return vehicleID; }

    virtual double calculateRentalCost(int days) = 0;
    virtual void displayDetails() {
        cout << "\n---------------------------";
        cout << "\nVehicle ID: " << vehicleID;
        cout << "\nMake: " << make;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
        cout << "\nRate: $" << dailyRentalRate << "/day";
        cout << "\nRented: " << (isRented ? "Yes" : "No");
    }

    void rentVehicle() { isRented = true; }
    void returnVehicle() { isRented = false; }
};

// Car derived class
class Car : public Vehicle {
    int numberOfDoors;
    string fuelType;

public:
    Car(string c_id, string c_make, string c_model, int c_year, double c_rate, int no_doors, string fuel)
        : Vehicle(c_id, c_make, c_model, c_year, c_rate), numberOfDoors(no_doors), fuelType(fuel) {}

    double calculateRentalCost(int days) { return dailyRentalRate * days; }

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "\nDoors: " << numberOfDoors;
        cout << "\nFuel: " << fuelType << endl;
    }
};

// Motorcycle derived class
class Motorcycle : public Vehicle {
    string engineType;
    bool hasSidecar;

public:
    Motorcycle(string m_id, string m_make, string m_model, int m_year, double m_rate, string eng_type, bool sideCar)
        : Vehicle(m_id, m_make, m_model, m_year, m_rate), engineType(eng_type), hasSidecar(sideCar) {}

    double calculateRentalCost(int days) {
        return dailyRentalRate * days + (hasSidecar ? 20 * days : 0);
    }

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "\nEngine: " << engineType;
        cout << "\nSide Car: " << (hasSidecar ? "Yes" : "No") << endl;
    }
};

// Truck derived class
class Truck : public Vehicle {
    double cargoCapacity;
    int numberOfAxles;

public:
    Truck(string t_id, string t_make, string t_model, int t_year, double t_rate, double capacity, int axles)
        : Vehicle(t_id, t_make, t_model, t_year, t_rate), cargoCapacity(capacity), numberOfAxles(axles) {}

    double calculateRentalCost(int days) {
        return dailyRentalRate * days + (cargoCapacity * 10 * days);
    }

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "\nCargo Capacity: " << cargoCapacity << " cubic meters";
        cout << "\nAxles: " << numberOfAxles << endl;
    }
};

// Rental System class
class RentalSystem {
    vector<Vehicle*> Vehicles;

public:
    void addVehicle(Vehicle* vehicle) { Vehicles.push_back(vehicle); }

    void displayAvailableVehicles() {
        cout << "\n------ Available Vehicles ------\n";
        for (auto v : Vehicles) {
            if (!v->getRentalStatus()) {
                v->displayDetails();
                cout << "---------------------------\n";
            }
        }
    }

    Vehicle* findVehicle(string target_id) {
        for (auto v : Vehicles) {
            if (v->getVehicleID() == target_id) {
                return v;
            }
        }
        return nullptr;
    }

    void rentVehicle(string v_id, int days) {
        Vehicle* v = findVehicle(v_id);
        if (v && !v->getRentalStatus()) {
            v->rentVehicle();
            cout << "\nRental Cost: $" << v->calculateRentalCost(days) << "\n";
        } else {
            cout << "\nVehicle with ID " << v_id << " is not available.\n";
        }
    }

    void returnVehicle(string v_id) {
        Vehicle* v = findVehicle(v_id);
        if (v && v->getRentalStatus()) {
            v->returnVehicle();
            cout << "\nVehicle with ID " << v_id << " returned successfully.\n";
        } else {
            cout << "\nVehicle with ID " << v_id << " is not rented or does not exist.\n";
        }
    }

    ~RentalSystem() {
        for (auto v : Vehicles) {
            delete v;
        }
        Vehicles.clear();
    }
};

// Main function
int main() {
    RentalSystem sys;
    sys.addVehicle(new Car("Car123", "Toyota", "Fortuner", 2020, 50, 5, "Petrol"));
    sys.addVehicle(new Motorcycle("Bike123", "Honda", "CBR", 2024, 20, "Inline-4", false));
    sys.addVehicle(new Truck("Truck123", "Ford", "F-150", 2018, 80, 5, 2));

    int ch;
    string vehicle_id;
    int days;

    do {
        cout << "\n======= Car Rental System =======";
        cout << "\n1. Display Available Vehicles";
        cout << "\n2. Rent a Vehicle";
        cout << "\n3. Return a Vehicle";
        cout << "\n4. Find Vehicle Details";
        cout << "\n5. Exit Program";
        cout << "\nEnter Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                sys.displayAvailableVehicles();
                break;
            case 2:
                cout << "Enter Vehicle ID: ";
                cin >> vehicle_id;
                cout << "Enter Number of Days: ";
                cin >> days;
                sys.rentVehicle(vehicle_id, days);
                break;
            case 3:
                cout << "Enter Vehicle ID: ";
                cin >> vehicle_id;
                sys.returnVehicle(vehicle_id);
                break;
            case 4:
                cout << "Enter Vehicle ID: ";
                cin >> vehicle_id;
                if (Vehicle* v = sys.findVehicle(vehicle_id)) {
                    v->displayDetails();
                    cout << "---------------------------\n";
                } else {
                    cout << "\nVehicle not found.\n";
                }
                break;
            case 5:
                cout << "\nExiting...\n";
                ch = 5; // Ensure graceful exit
                break;
            default:
                cout << "\nInvalid Choice.\n";
        }
    } while (ch != 5);

    return 0;
}
