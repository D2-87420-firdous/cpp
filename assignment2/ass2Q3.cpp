#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string building;
    string street;
    string city;
    int pin;

public:
    // Default constructor
    Address() : building(""), street(""), city(""), pin(0) {}

    // Parameterized constructor
    Address(string b, string s, string c, int p) : building(b), street(s), city(c), pin(p) {}

    // Getters
    string getBuilding() { return building; }
    string getStreet() { return street; }
    string getCity() { return city; }
    int getPin() { return pin; }

    // Setters
    void setBuilding(string b) { building = b; }
    void setStreet(string s) { street = s; }
    void setCity(string c) { city = c; }
    void setPin(int p) { pin = p; }

    // Accept function to input address details
    void accept() {
        cout << "Enter building: ";
        getline(cin, building);
        cout << "Enter street: ";
        getline(cin, street);
        cout << "Enter city: ";
        getline(cin, city);
        cout << "Enter pin: ";
        cin >> pin;
        cin.ignore();  // Ignore the newline character left in the buffer
    }

    // Display function to print address details
    void display() {
        cout << "Building: " << building << endl;
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "Pin: " << pin << endl;
    }
};

int main() {
    // Using the default constructor
    Address addr1;
    cout << "Default Address:" << endl;
    addr1.display();

    // Using the parameterized constructor
    Address addr2("Apt 101", "Baker Street", "London", 123456);
    cout << "\nParameterized Address:" << endl;
    addr2.display();

    // Using setters to update address
    addr1.setBuilding("Flat 202");
    addr1.setStreet("Elm Street");
    addr1.setCity("Springfield");
    addr1.setPin(654321);
    cout << "\nUpdated Address using setters:" << endl;
    addr1.display();

    // Accepting user input for address
    Address addr3;
    cout << "\nEnter Address details:" << endl;
    addr3.accept();
    cout << "\nEntered Address:" << endl;
    addr3.display();

    return 0;
}
