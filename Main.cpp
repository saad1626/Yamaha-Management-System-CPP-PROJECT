#include <iostream>
#include "Customer.h"
using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "---------------------------------------" << endl;
        cout << setw(20) << "Main Menu" << endl;
        cout << "---------------------------------------" << endl;
        cout << "1. Vehicle Management" << endl;
        cout << "2. Service Management" << endl;
        cout << "3. Customer Management" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            Yamaha_Management_System();
            break;
        case 2:
           servicesfunction();
           break;
        case 3:
            customer();
            break;
        case 4:
            cout << "Exit";
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    system("pause>0");
    return 0;
}