#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Global variable for roll number generation
int rollNumberCounter = 1000;

// Class Student definition
class Student {
private:
    string name;
    string gender;
    int rollNumber;
    int marks[3];

public:
    // Default constructor
    Student() : rollNumber(++rollNumberCounter) {
        name = "";
        gender = "";
        for (int i = 0; i < 3; ++i) {
            marks[i] = 0;
        }
    }

    // Method to accept student details from user
    void acceptDetails() {
        cout << "Enter name: ";
        cin.ignore(); // Clear newline character from input buffer
        getline(cin, name);
        cout << "Enter gender (M/F): ";
        cin >> gender;
        cout << "Enter marks for 3 subjects:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Marks for subject " << (i + 1) << ": ";
            cin >> marks[i];
        }
    }

    // Method to calculate and return percentage
    float calculatePercentage() const {
        int total = 0;
        for (int i = 0; i < 3; ++i) {
            total += marks[i];
        }
        return (total / 3.0f);
    }

    // Method to print student details
    void printDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Gender: " << gender << endl;
        cout << "Percentage: " << fixed << setprecision(2) << calculatePercentage() << "%" << endl;
    }

    // Getter for roll number
    int getRollNumber() const {
        return rollNumber;
    }
};

// Global function to sort students based on roll number in descending order
void sortRecords(Student* arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i]->getRollNumber() < arr[j]->getRollNumber()) {
                // Swap
                Student* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Global function to search for a student by roll number
int searchRecords(Student* arr[], int size, int rollNumber) {
    for (int i = 0; i < size; ++i) {
        if (arr[i]->getRollNumber() == rollNumber) {
            return i;
        }
    }
    return -1;
}

// Main function
int main() {
    const int SIZE = 5;
    Student* arr[SIZE];
    int choice, index, rollNumberToSearch;

    // Initialize student array
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = new Student();
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Accept Student Details\n";
        cout << "2. Print All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Sort Students by Roll Number (Descending)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Accept student details
                for (int i = 0; i < SIZE; ++i) {
                    cout << "Enter details for student " << (i + 1) << ":" << endl;
                    arr[i]->acceptDetails();
                }
                break;
            
            case 2:
                // Print all student details
                for (int i = 0; i < SIZE; ++i) {
                    cout << "\nStudent " << (i + 1) << " Details:" << endl;
                    arr[i]->printDetails();
                }
                break;

            case 3:
                // Search for a student by roll number
                cout << "Enter roll number to search: ";
                cin >> rollNumberToSearch;
                index = searchRecords(arr, SIZE, rollNumberToSearch);
                if (index != -1) {
                    cout << "\nStudent found:" << endl;
                    arr[index]->printDetails();
                } else {
                    cout << "Student with roll number " << rollNumberToSearch << " not found." << endl;
                }
                break;

            case 4:
                // Sort students by roll number
                sortRecords(arr, SIZE);
                cout << "Students sorted by roll number in descending order." << endl;
                break;

            case 5:
                // Exit
                cout << "Exiting..." << endl;
                // Free allocated memory
                for (int i = 0; i < SIZE; ++i) {
                    delete arr[i];
                }
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }

    } while (choice != 5);

    return 0;
}
