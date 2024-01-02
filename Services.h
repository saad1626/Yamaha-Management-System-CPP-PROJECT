#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_SERVICES = 100; // Global variable to define Maximum Services.
const int ATTRIBUTES = 4;     // Global variable to define number of columns of attributes.

struct Service
{
    int serviceID;
    string serviceCategory;
    double serviceCost;
    int serviceMileage;
};
    Service *servicesP = new Service[MAX_SERVICES];
    int numServices = 0;


void servicesfunction();
void writeFile(int numServices);
void readFile( int &numServices);
void deleteservices(int &numServices);
void updateservices(int numServices);
void searchservices(int numServices);
void viewservices( int numServices);
void addservices( int &numServices);

void addservices(int &numServices)
{
    if (numServices < MAX_SERVICES)
    {
        cout << "Enter Service ID: ";
        cin >> servicesP[numServices].serviceID;

        cout << "Enter Service Category: ";
        cin >> servicesP[numServices].serviceCategory;

        cout << "Enter Service Cost: ";
        cin >> servicesP[numServices].serviceCost;

        cout << "Enter Service Mileage: ";
        cin >> servicesP[numServices].serviceMileage;

        numServices++;
        cout << "Service Added Successfully!" << endl;
        writeFile(numServices);
    }
    else
    {
        cout << "Service database is full. Cannot add more services." << endl;
    }
}

void viewservices(int numServices)
{
    if (numServices > 0)
    {
        cout << setw(5) << "ID" << setw(20) << "Category" << setw(15) << "Cost" << setw(20) << "Mileage" << endl;
        for (int i = 0; i < numServices; i++)
        {
            cout << setw(5) << servicesP[i].serviceID << setw(20) << servicesP[i].serviceCategory
                 << setw(15) << servicesP[i].serviceCost << setw(20) << servicesP[i].serviceMileage << endl;
        }
    }
    else
    {
        cout << "No services available in the database." << endl;
    }
}

void searchservices( int numServices)
{
    if (numServices > 0)
    {
        int searchID;
        cout << "Enter Service ID to search: ";
        cin >> searchID;

        bool found = false;
        for (int i = 0; i < numServices; i++)
        {
            if (servicesP[i].serviceID == searchID)
            {
                cout << "Service Found!" << endl;
                cout << "ID: " << servicesP[i].serviceID << endl;
                cout << "Category: " << servicesP[i].serviceCategory << endl;
                cout << "Cost: " << servicesP[i].serviceCost << endl;
                cout << "Mileage: " << servicesP[i].serviceMileage << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Service with ID " << searchID << " not found." << endl;
        }
    }
    else
    {
        cout << "No services available in the database." << endl;
    }
}

void updateservices( int numServices)
{
    if (numServices > 0)
    {
        int updateID;
        cout << "Enter Service ID to update: ";
        cin >> updateID;

        bool found = false;
        for (int i = 0; i < numServices; i++)
        {
            if (servicesP[i].serviceID == updateID)
            {
                cout << "Service Found!" << endl;
                cout << "Current Category: " << servicesP[i].serviceCategory << endl;
                cout << "Enter New Category: ";
                cin >> servicesP[i].serviceCategory;

                cout << "Current Cost: " << servicesP[i].serviceCost << endl;
                cout << "Enter New Cost: ";
                cin >> servicesP[i].serviceCost;

                cout << "Current Mileage: " << servicesP[i].serviceMileage << endl;
                cout << "Enter New Mileage: ";
                cin >> servicesP[i].serviceMileage;

                found = true;
                cout << "Service Updated Successfully!" << endl;
                break;
            }
        }

        if (!found)
        {
            cout << "Service with ID " << updateID << " not found." << endl;
        }

        writeFile( numServices);
    }
    else
    {
        cout << "No services available in the database." << endl;
    }
}

void deleteservices( int &numServices)
{
    if (numServices > 0)
    {
        int deleteID;
        cout << "Enter Service ID to delete: ";
        cin >> deleteID;

        bool found = false;
        for (int i = 0; i < numServices; i++)
        {
            if (servicesP[i].serviceID == deleteID)
            {
                cout << "Service Found!" << endl;
                cout << "Deleting Service..." << endl;

                // Shifting remaining services to fill the gap
                for (int j = i; j < numServices - 1; j++)
                {
                    servicesP[j] = servicesP[j + 1];
                }

                numServices--;
                found = true;
                cout << "Service Deleted Successfully!" << endl;
                break;
            }
        }

        if (!found)
        {
            cout << "Service with ID " << deleteID << " not found." << endl;
        }

        writeFile( numServices);
    }
    else
    {
        cout << "No services available in the database." << endl;
    }
}

void readFile(int &numServices)
{
    ifstream fin("services.txt");
    if (fin.is_open())
    {
        while (fin >> servicesP[numServices].serviceID >> servicesP[numServices].serviceCategory >> servicesP[numServices].serviceCost >> servicesP[numServices].serviceMileage)
        {
            numServices++;
        }
        fin.close();
    }
}

void writeFile( int numServices)
{
    ofstream fout("services.txt");
    if (fout.is_open())
    {
        for (int i = 0; i < numServices; i++)
        {
            fout << servicesP[i].serviceID << " " << servicesP[i].serviceCategory << " "
                 << servicesP[i].serviceCost << " " << servicesP[i].serviceMileage << endl;
        }
        fout.close();
    }
}

void servicesfunction()
{
    readFile( numServices);

    int choice;
    while (true)
    {
        cout << "---------------------------------------" << endl;
        cout << setw(20) << "Service" << endl;
        cout << "---------------------------------------" << endl;
        cout << "1. Add Services\n2. View Services\n3. Search Services\n";
        cout << "4. Update Services\n5. Delete Services\n6. Return to the Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "---------------------------------------" << endl;
            cout << "Calling Add Service Data Function!" << endl;
            cout << "---------------------------------------" << endl;
            addservices(numServices);
            cout << endl;
            system("pause>0");
            break;
        case 2:
            cout << "---------------------------------------" << endl;
            cout << "Calling View Service Data Function!" << endl;
            cout << "---------------------------------------" << endl;
            viewservices(numServices);
            cout << endl;
            system("pause>0");
            break;
        case 3:
            cout << "---------------------------------------" << endl;
            cout << "Calling Search Service Data Function!" << endl;
            cout << "---------------------------------------" << endl;
            searchservices(numServices);
            system("pause>0");
            break;
        case 4:
            cout << "---------------------------------------" << endl;
            cout << "Calling Update Service Data Function!" << endl;
            cout << "---------------------------------------" << endl;
            updateservices( numServices);
            cout << endl;
            system("pause>0");
            break;
        case 5:
            cout << "---------------------------------------" << endl;
            cout << "Calling Delete Service Data Function!" << endl;
            cout << "---------------------------------------" << endl;
            deleteservices( numServices);
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
