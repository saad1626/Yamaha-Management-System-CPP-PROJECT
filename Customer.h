#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Services.h"
#include "Vehicle.h"
using namespace std;

struct Customer
{
    int id;
    string name;
    int serviceFee;
};

void customer();
void search_record(int numCustomers);
void readCustomerFile(Customer *customer, int &numCustomer);
void saveToFile(Customer *customer, int &numCustomer);
void display_record(int &numCustomer);
void add_record(Customer *customer, int &numCustomer);

const int Max_Customer = 100;
const int Attributes = 12;

// Declaring a single pointer to store dynamically allocated memory for 2D array
Customer *customerArray = nullptr;

void customer()
{
    int numCustomer = 0;
    readFile(numCustomer);
    cout << "numCustomer " << numCustomer << endl;
    int choice;
    while (true)
    {

        cout << "---------------------------------" << endl;
        cout << setw(20) << "Customers" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
        cout << "\nMenu:\n";
        cout << endl;
        cout << "1. Display entire Database." << endl;
        cout << "2. Search for Record." << endl;
        cout << "3. Add a new Record." << endl;
        cout << "4. Back to the Main Menu." << endl;
        cout << endl;
        cout << "Enter your Choice:";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "---------------------------------" << endl;
            cout << "Calling View Database Function!" << endl;
            cout << "---------------------------------" << endl;
            display_record(numCustomer);
            cout << endl;
            system("pause>0");
            break;
        case 2:
            cout << "---------------------------------" << endl;
            cout << "Calling Search Database Function! " << endl;
            cout << "---------------------------------" << endl;
            search_record(numCustomer);
            cout << endl;
            system("pause>0");
            break;
        case 3:
            cout << "---------------------------------" << endl;
            cout << "Calling Add Customer Function! " << endl;
            cout << "---------------------------------" << endl;
            add_record(customerArray, numCustomer);
            cout << endl;
            system("pause>0");
            break;
        case 4:
            cout << "Directing to the Main Menu..." << endl;
            return;
            system("pause>null");
        default:
            cout << "Whoops! It seems like you've ventured  into uncharted territories. Please choose a valid option. \n";
            break;
        }
    }
}
void display_record(int &numCustomer)
{
    if (numCustomer > 0)
    {
        for (int i = 0; i < numCustomer; ++i)
        {

            // Displaying customer details
            cout << "Name: " << customerArray[numCustomer].name;
            cout << "Service Fee " << customerArray[numCustomer].serviceFee << endl;
            cout << "Service ID : " << servicesP[numCustomer].serviceID << endl;
        }
    }
    else
    {
        cout << "---------------------------------" << endl;
        cout << "No data Found " << endl;
        cout << "---------------------------------" << endl;
    }
}

void search_record(int numCustomer)
{
    // Call readFile to load data into the 2D array
    if (numCustomer > 0 && numCustomer < Max_Customer)
    {
        int searchID;
        cout << "Enter Service ID to search : ";
        cin >> searchID;

        // Search for the record with the given email

        for (int i = 0; i < numCustomer; ++i)
        {
            if (servicesP[numServices].serviceID == searchID)
            {
                // Display the found record
                cout << "Name: " << customerArray[numCustomer].name;
                cout << "Service Fee " << customerArray[numCustomer].serviceFee << endl;
                cout << "Service ID : " << servicesP[numCustomer].serviceID << endl;
                break;
            }
            else
            {
                cout << "Record not found." << endl;
                break;
            }
        }
    }
    else
    {
        cout << "Customer Data Is empty " << endl;
    }

    // Deallocate memory when done
    delete[] customerArray;
}
void add_record(Customer *customer, int &numCustomer)
{
    if (numCustomer < Max_Customer)
    {
        // Taking input from the user
        cout << "\nFor service ID " << servicesP[numServices].serviceID << endl;
        // the uper line picks Service ID from project 2 file
        cout << "Service Fee ";
        cin >> customerArray[numCustomer].serviceFee;

        cout << "Customer Name :";
        cin >> customer[numCustomer].name;
        cout << "Num OF customer : " << numCustomer << endl;

        saveToFile(customer, numCustomer); // Now saving data to file we just call the function
        numCustomer++;
    }
    else
    {
        cout << "Maximum number of Customers reached.\n";
    }
}
void saveToFile(Customer *customer, int &numCustomer)
{ // Function to save tour data to a file
    ofstream fout;
    fout.open("Finale.txt"); // Opening new file

    if (fout.fail())
    {
        cout << "Error opening file for writing." << endl; // Error handling
        return;
    }

    for (int i = 0; i <= numCustomer; ++i)
    {
        fout << customer[i].name << " " << servicesP[i].serviceID << " " << customer[i].serviceFee << endl; // Writing in file
    }

    fout.close();
}

void readCustomerFile(Customer *customer, int &numCustomer)
{
    ifstream fin;
    ifstream nameFile("Yamaha Management System.txt"); // File of project 1
    ifstream destinationFile("services.txt");          // File of project 2

    if (!nameFile.is_open() || !destinationFile.is_open())
    {
        cout << "Error opening files\n";
        return; // Error handling
    }

    fin.open("Finale.txt");

    if (fin.fail())
    {
        cout << "Error opening file for reading. Starting with an empty data set." << endl;
        return; // Error handling
    }

    numCustomer = 0; // Reset tour count to pick data from the start of the file

    while (fin >> customer[numCustomer].id >> customer[numCustomer].name >> customer[numCustomer].serviceFee)
    {
        numCustomer++; // Loading data into the struct of tour
    }

    fin.close(); // File closing
}
