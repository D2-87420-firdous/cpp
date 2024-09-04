#include <iostream>
#include <string>

using namespace std;

// Class Date definition
class Date {
private:
    int day;
    int month;
    int year;

public:
    // Default constructor
    Date() : day(1), month(1), year(2000) {}

    // Parameterized constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Function to initialize date
    void initDate(int d = 1, int m = 1, int y = 2000) {
        day = d;
        month = m;
        year = y;
    }

    // Function to print date
    void printDate() const {
        cout << day << "/" << month << "/" << year << endl;
    }

    // Function to accept date from console
    void acceptDateFromConsole() {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }

    // Function to check if the year is a leap year
    bool isLeapYear() const {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return true;
        }
        return false;
    }
};

// Class Person definition
class Person {
private:
    string name;
    string address;
    Date birthDate;

public:
    // Default constructor
    Person() : name("Unknown"), address("Unknown"), birthDate(Date()) {}

    // Parameterized constructor
    Person(const string& n, const string& a, const Date& bDate) 
        : name(n), address(a), birthDate(bDate) {}

    // Function to accept person details from console
    void acceptPersonFromConsole() {
        cout << "Enter name: ";
        cin.ignore(); // To clear the newline character from the input buffer
        getline(cin, name);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter birthdate:" << endl;
        birthDate.acceptDateFromConsole();
    }

    // Function to print person details
    void printPersonDetails() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: ";
        birthDate.printDate();
    }
};

// Main function to test the classes
int main() {
    // Create and initialize Date object
    Date defaultDate;
    defaultDate.initDate();
    cout << "Default date initialized: ";
    defaultDate.printDate();

    // Create and initialize Person object
    Person person1("Alice", "123 Main St", Date(15, 6, 1990));
    cout << "\nPerson 1 details:" << endl;
    person1.printPersonDetails();

    // Modify person details using console input
    Person person2;
    cout << "\nEnter details for Person 2:" << endl;
    person2.acceptPersonFromConsole();
    cout << "\nPerson 2 details:" << endl;
    person2.printPersonDetails();

    // Check leap year functionality
    cout << "\nChecking if birth year of Person 2 is a leap year:" << endl;
    if (person2.isLeapYear()) {
        cout << "The birth year is a leap year." << endl;
    } else {
        cout << "The birth year is not a leap year." << endl;
    }

    return 0;
}
