#include <iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;

    void initDate() {
        day = 1;
        month = 1;
        year = 2000;
        cout << "Date initialized to: " << day << "/" << month << "/" << year << endl;
    }

    void printDateOnConsole() const {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    void acceptDateFromConsole() {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
         cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    bool isLeapYear() const {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                return year % 400 == 0;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Date date;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Initialize Date\n";
        cout << "2. Print Date\n";
        cout << "3. Enter Date\n";
        cout << "4. Check Leap Year\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                date.initDate();
                break;
            case 2:
                date.printDateOnConsole();
                break;
            case 3:
                date.acceptDateFromConsole();
                break;
            case 4:
                if (date.isLeapYear()) {
                    cout << date.year << " is a leap year." << endl;
                } else {
                    cout << date.year << " is not a leap year." << endl;
                }
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
