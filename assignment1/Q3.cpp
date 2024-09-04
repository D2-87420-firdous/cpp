#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    //to initialize
    void initStudent() {
        rollNo = 0;
        name = "Unknown";
        marks = 0.0;
        cout << "Student initialized with default values.\n";
    }

    //print student
    void printStudentOnConsole() const {
        cout << "Roll No: " << rollNo << "\n";
        cout << "Name: " << name << "\n";
        cout << "Marks: " << marks << "\n";
    }

    // Function to accept student details from the console
    void acceptStudentFromConsole() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore();  // To ignore the newline character after the roll number input
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }
};

int main() {
    Student student;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Initialize Student\n";
        cout << "2. Print Student Details\n";
        cout << "3. Enter Student Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                student.initStudent();
                break;
            case 2:
                student.printStudentOnConsole();
                break;
            case 3:
                student.acceptStudentFromConsole();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
