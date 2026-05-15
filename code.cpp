#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CrimeReport {
public:
    int id;
    string title;
    string description;
    string location;

    void input() {
        cout << "Enter Report ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Crime Title: ";
        getline(cin, title);

        cout << "Enter Description: ";
        getline(cin, description);

        cout << "Enter Location: ";
        getline(cin, location);
    }

    void display() {
        cout << "\nReport ID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nDescription: " << description;
        cout << "\nLocation: " << location;
        cout << "\n---------------------------\n";
    }
};

void addReport() {
    CrimeReport c;
    ofstream file("crime.txt", ios::app);

    c.input();

    file << c.id << endl;
    file << c.title << endl;
    file << c.description << endl;
    file << c.location << endl;

    file.close();

    cout << "\nReport Added Successfully!\n";
}

void viewReports() {
    ifstream file("crime.txt");
    CrimeReport c;

    while (file >> c.id) {
        file.ignore();
        getline(file, c.title);
        getline(file, c.description);
        getline(file, c.location);

        c.display();
    }

    file.close();
}

void searchReport() {
    ifstream file("crime.txt");
    CrimeReport c;
    int searchId;
    bool found = false;

    cout << "Enter Report ID to search: ";
    cin >> searchId;

    while (file >> c.id) {
        file.ignore();
        getline(file, c.title);
        getline(file, c.description);
        getline(file, c.location);

        if (c.id == searchId) {
            c.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Report not found!\n";
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== Crime Reporting System =====\n";
        cout << "1. Add Report\n";
        cout << "2. View Reports\n";
        cout << "3. Search Report\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addReport();
                break;
            case 2:
                viewReports();
                break;
            case 3:
                searchReport();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}