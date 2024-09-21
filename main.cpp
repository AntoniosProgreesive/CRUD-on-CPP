#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Δομή για την αποθήκευση πληροφοριών πελάτη / Structure for storing customer information
struct Customer {
    int id;             // Μοναδικός αριθμός αναγνώρισης / Unique identification number
    string name;        // Όνομα πελάτη / Customer's name
    int age;            // Ηλικία πελάτη / Customer's age
};

// Προσθήκη νέου record / Add new record
void addRecord(const string& filename) {
    Customer customer;
    cout << "Enter ID: ";
    cin >> customer.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, customer.name);
    cout << "Enter Age: ";
    cin >> customer.age;

    // Άνοιγμα αρχείου για προσθήκη / Open file for appending
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << customer.id << " " << customer.name << " " << customer.age << endl;
        file.close();
        cout << "Record added successfully." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Εμφάνιση όλων των records / Show all records
void listRecords(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        Customer customer;
        while (file >> customer.id >> ws && getline(file, customer.name, ' ') && file >> customer.age) {
            cout << "ID: " << customer.id << ", Name: " << customer.name << ", Age: " << customer.age << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Αναζήτηση record βάσει ID / Search record by ID
void searchaRecord(const string& filename, int id) {
    ifstream file(filename);
    if (file.is_open()) {
        Customer customer;
        bool found = false;
        while (file >> customer.id >> ws && getline(file, customer.name, ' ') && file >> customer.age) {
            if (customer.id == id) {
                cout << "Record found: ID: " << customer.id << ", Name: " << customer.name << ", Age: " << customer.age << endl;
                found = true;
                break;
            }
        }
        file.close();
        if (!found) {
            cout << "Record with ID " << id << " not found." << endl;
        }
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Επεξεργασία record βάσει ID / Edit record by ID
void editRecord(const string& filename, int id) {
    ifstream file(filename);
    vector<Customer> customers;
    if (file.is_open()) //{
        Customer customer;
        bool found = false;
        while (file >> customer.id >> ws && getline(file, customer.name, ' ') && file >> customer.age) {
            if (customer.id == id) {
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, customer.name);
                cout << "Enter new age: ";
                cin >> customer.age;
                found = true;
            }
            customers.push_back(customer);
        }
        file.close();

        if (found) {
            ofstream outFile(filename);
            for (const auto& cust : customers) {
                outFile << cust.id << " " << cust.name << " " << cust.age << endl;
            }
            outFile.close();
            cout << "Record updated successfully." << endl;
        } else {
            cout << "Record with ID " << id << " not found." << endl;
        }
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Διαγραφή record βάσει ID / Delete record by ID
void deleteRecord(const string& filename, int id) {
    ifstream file(filename);
    vector<Customer> customers;
    if (file.is_open()) {
        Customer customer;
        bool found = false;
        while (file >> customer.id >> ws && getline(file, customer.name, ' ') && file >> customer.age) {
            if (customer.id != id) {
                customers.push_back(customer);
            } else {
                found = true;
            }
        }
        file.close();

        if (found) {
            ofstream outFile(filename);
            for (const auto& cust : customers) {
                outFile << cust.id << " " << cust.name << " " << cust.age << endl;
            }
            outFile.close();
            cout << "Record deleted successfully." << endl;
        } else {
            cout << "Record with ID " << id << " not found." << endl;
        }
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Κύριο μενού / Main menu
void menu(const string& filename) {
    int choice;
    do {
        cout << "\n1. Add Record\n2. List Records\n3. Search Record\n4. Edit Record\n5. Delete Record\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord(filename);
                break;
            case 2:
                listRecords(filename);
                break;
            case 3: {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                searchRecord(filename, id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter ID to edit: ";
                cin >> id;
                editRecord(filename, id);
                break;
            }
            case 5: {
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                deleteRecord(filename, id);
                break;
            }
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
}

// Κύριο πρόγραμμα / Main program
int main() {
    string filename = "records.txt";  // Το όνομα του αρχείου / The file name
    menu(filename);                   // Εκτέλεση μενού / Run the menu
    return 0;
}
