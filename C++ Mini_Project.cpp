#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>  
using namespace std;

struct Patient 
{
    int id;
    string password;
    string name;
    int age;
    string address;
};

int generateRandomId()
 {
    srand(time(nullptr));
    return rand() % 9000 + 1000;
}

int main()
 {
    vector<Patient> patients;
    while (true)
     {
        string choice;
        cout << "Patient Registration System\n";
        cout << "1. Register new patient\n";
        cout << "2. Patient Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") 
        {
            Patient newPatient;
            newPatient.id = generateRandomId();

            cout << "Enter patient name: ";
            cin >> newPatient.name;
            cout << "Enter patient age: ";
            cin >> newPatient.age;
            cout << "Enter patient address: ";
            cin.ignore();
            getline(std::cin, newPatient.address);
            cout << "Patient registered successfully. Your ID is: " << newPatient.id << std::endl;

            cout << "Create your own password for your ID - ";
            cin >> newPatient.password;
            patients.push_back(newPatient);

            
        }
         else if (choice == "2") 
        {
         
            int id;
            string password;

            cout << "Enter your ID: ";
            cin >> id;
            cout << "Enter your password: ";
            cin >> password;

            bool found = false;
            for (const auto& patient : patients) {
                if (patient.id == id && patient.password == password) {
                    found = true;
                    cout << "Login successful.\n Patient Information :\n";
                    cout << "Name: " << patient.name << std::endl;
                    cout << "Age: " << patient.age <<endl;
                    cout << "Address: " << patient.address <<endl;
                    break;
                }
            }

            if (!found)
             {
                cout << "Invalid ID or password. Please try again.\n";
            }
        } 
        else if (choice == "3")
         {
            cout << "Exiting the program.\n";
            break;
        }
         else {
            cout << "Invalid choice. Please try again.\n";
        }

        cout <<endl;
    }

    return 0;
}