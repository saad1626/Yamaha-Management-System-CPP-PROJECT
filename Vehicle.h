#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Vehicle {
    string name;
    string color;
    string chassisNumber;
    string engineNumber;
};
void create_File();
void delete_Vehicle();
void update_Vehicle();
void add_Vehicle();
void search_Bike();
void display_Database();
void Yamaha_Management_System();

void Yamaha_Management_System() {
    create_File();
    int choice;
    while (true) {
        cout << "---------------------------------" << endl;
        cout << setw(20) << "Vehicles" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
        cout << "\nMenu:\n";
        cout << endl;
        cout << "1. Display entire Database." << endl;
        cout << "2. Search for a Bike." << endl;
        cout << "3. Add a new vehicle." << endl;
        cout << "4. Update vehicle info." << endl;
        cout << "5. Delete vehicle info." << endl;
        cout << "6. Back to the Main Menu." << endl;
        cout << endl;
        cout << "Enter your Choice:";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1:
            cout << "---------------------------------" << endl;
            cout << "Calling View Database Function!" << endl;
            cout << "---------------------------------" << endl;
            display_Database();
            cout << endl;
            system("pause>0");
            break;
        case 2:
            cout << "---------------------------------" << endl;
            cout << "Calling Search Bike Function! " << endl;
            cout << "---------------------------------" << endl;
            search_Bike();
            cout << endl;
            system("pause>0");
            break;
        case 3:
            cout << "---------------------------------" << endl;
            cout << "Calling Add Vehicle Function! " << endl;
            cout << "---------------------------------" << endl;
            add_Vehicle();
            cout << endl;
            system("pause>0");
            break;
        case 4:
            cout << "---------------------------------" << endl;
            cout << "Calling Update Vehicle Function! " << endl;
            cout << "---------------------------------" << endl;
            update_Vehicle();
            cout << endl;
            system("pause>0");
            break;
        case 5:
            cout << "---------------------------------" << endl;
            cout << "Calling Delete Vehicle Function! " << endl;
            cout << "---------------------------------" << endl;
            delete_Vehicle();
            cout << endl;
            system("pause>0");
            break;
        case 6:
            cout << "Directing to the Main Menu..." << endl;
            return;
            system("pause>null");
        default:
            cout << "Whoops! It seems like you've ventured  into uncharted territories. Please choose a valid option. \n";
            break;
        }
    }
}

void create_File() 
{
    ofstream fout;
    fout.open("Yamaha Management System02.txt");
    fout.close();
}

void display_Database() {
    ifstream fin;
    fin.open("Yamaha Management System02.txt");
    string line;
    if (fin.is_open()) {
        cout << "Name    " << setw(15) << "Color  " << setw(30) << "Chassis Number" << setw(25) << "Engine Number" << endl;
        cout << endl;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    }
    else {
        cout << "Unable to open the file" << endl;
    }
}

void search_Bike() {
    ifstream fin;
    fin.open("Yamaha Management System02.txt");
    bool found = false;
    cout << "Enter name of the bike: ";
    string name, namefile, color, chassis, engine;
    cin >> name;
    while (fin >> namefile >> color >> chassis >> engine) {
        if (namefile == name) {
            cout << "Bike Found! " << endl;
            cout << endl;
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Name: " << namefile << endl;
        cout << "Color: " << color << endl;
        cout << "Chassis Number: " << chassis << endl;
        cout << "Engine Number: " << engine << endl;
    }
    else {
        cout << "Bike not found! " << endl;
    }
    fin.close();
}

void add_Vehicle() {
    ofstream fout;
    fout.open("Yamaha Management System02.txt", ios::app);
    if (fout.is_open()) {
        Vehicle newVehicle;
        cout << "\nEnter the bike name(only First Name): ";
        cin >> newVehicle.name;
        cout << "\nEnter the color of bike: ";
        cin >> newVehicle.color;
        cout << "\nEnter chassis Number(Only 6 Characters): ";
        cin >> newVehicle.chassisNumber;
        cout << "\nEnter Engine Number(Only 6 Characters): ";
        cin >> newVehicle.engineNumber;
        fout << newVehicle.name << setw(20) << newVehicle.color << setw(25) << newVehicle.chassisNumber << setw(25) << newVehicle.engineNumber << endl;
        fout.close();
        cout << "Vehicle Added Successfully!" << endl;
    }
    else {
        cout << "Unable to open the file! " << endl;
    }
}

void update_Vehicle() {
    ifstream fin;
    fin.open("Yamaha Management System02.txt");
    ofstream updateFile("update.txt");
    string name, color, chassis, engine;
    bool found = false;
    string nameFind;
    string updatedColor, updatedChassis, updatedEngine;
    cout << "Enter name of Bike you want to update : ";
    cin >> nameFind;
    while (fin >> name >> color >> chassis >> engine) {
        if (nameFind == name) {
            found = true;
            cout << "Color: " << color << endl
                << "chassis: " << chassis << endl
                << "Engine: " << engine << endl;
            cout << "Enter Color you want to update : ";
            cin >> updatedColor;
            cout << "Enter Chassis you want to update : ";
            cin >> updatedChassis;
            cout << "Enter Engine # you want to update : ";
            cin >> updatedEngine;
            updateFile << name << "    " << setw(15) << updatedColor << "  " << setw(25) << updatedChassis << setw(25) << updatedEngine << endl;
            cout << "Record Updated Successfully";
        }
        else {
            updateFile << name << "    " << setw(15) << color << "  " << setw(25) << chassis << setw(25) << engine << endl;
        }
    }
    if (!found) {
        cout << "Record doesnt exists";
    }

    fin.close();
    updateFile.close();
    remove("Yamaha Management System02.txt");
    rename("update.txt", "Yamaha Management System02.txt");
}

void delete_Vehicle() {
    ifstream fin("Yamaha Management System02.txt");
    if (fin.is_open()) {
        ofstream deleteFile("delete.txt");
        string name, color, chassis, engine;
        bool found = false;
        string delete_name;
        cout << "Enter name of bike you want to delete : ";
        cin >> delete_name;
        while (fin >> name >> color >> chassis >> engine) {
            if (name == delete_name) {
                cout << "Record found" << endl
                    << "Name :" << name << endl
                    << "Color : " << color << endl
                    << "chassis : " << chassis << endl
                    << "Engine : " << engine << endl;
                found = true;
            }
            else {
                deleteFile << name << "    " << setw(15) << color << "   " << setw(25) << chassis << setw(25) << engine << endl;
            }
        }
        if (!found) {
            cout << "Record doesnt exists";
        }
        else {
            cout << "Record has been deleted!" << endl;
        }

        fin.close();
        deleteFile.close();
        remove("Yamaha Management System02.txt");
        rename("delete.txt", "Yamaha Management System02.txt");
    }
}