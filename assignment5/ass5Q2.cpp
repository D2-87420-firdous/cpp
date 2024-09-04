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

    // Method to set the date
    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    // Method to print the date
    void printDate() const {
        cout << day << "/" << month << "/" << year;
    }
};

// Class Person definition
class Person {
protected:
    string name;
    string address;
    Date birthdate;

public:
    // Default constructor
    Person() : name(""), address("") {}

    // Parameterized constructor
    Person(const string& n, const string& a, const Date& bDate) 
        : name(n), address(a), birthdate(bDate) {}

    // Method to set personal details
    void setPersonDetails(const string& n, const string& a, const Date& bDate) {
        name = n;
        address = a;
        birthdate = bDate;
    }

    // Method to print person details
    void printPersonDetails() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: ";
        birthdate.printDate();
        cout << endl;
    }
};

// Class Employee definition
class Employee : public Person {
private:
    int id;
    float sal;
    string dept;
    Date joiningDate;

public:
    // Default constructor
    Employee() : Person(), id(0), sal(0.0), dept(""), joiningDate(Date()) {}

    // Parameterized constructor
    Employee(const string& n, const string& a, const Date& bDate, 
             int i, float s, const string& d, const Date& jDate) 
        : Person(n, a, bDate), id(i), sal(s), dept(d), joiningDate(jDate) {}

    // Method to set employee details
    void setEmployeeDetails(int i, float s, const string& d, const Date& jDate) {
        id = i;
        sal = s;
        dept = d;
        joiningDate = jDate;
    }

    // Method to print employee details
    void printEmployeeDetails() const {
        printPersonDetails();
        cout << "ID: " << id << endl;
        cout << "Salary: " << sal << endl;
        cout << "Department: " << dept << endl;
        cout << "Joining Date: ";
        joiningDate.printDate();
        cout << endl;
    }
};

// Main function to test the classes
int main() {
    // Creating Date objects
    Date birthDate(15, 5, 1990);
    Date joiningDate(1, 6, 2020);

    // Creating Person object
    Person person("John Doe", "123 Elm Street", birthDate);
    cout << "Person Details:" << endl;
    person.printPersonDetails();

    // Creating Employee object
    Employee employee("Alice Smith", "456 Oak Avenue", birthDate, 1001, 75000.0, "HR", joiningDate);
    cout << "\nEmployee Details:" << endl;
    employee.printEmployeeDetails();

    return 0;
}
