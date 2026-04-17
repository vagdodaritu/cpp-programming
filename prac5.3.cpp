#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void tolower(string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}
void additem() {
    ofstream fout("inventory.txt", ios::app);

    if (!fout) {
        cerr << "File error!\n";
        return;
    }
    string name;
    int qty;
    float price;
    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> qty;
    cout << "Enter price: ";
    cin >> price;

    fout << name << " " << qty << " " << price << endl;

    fout.close();
    cout << "Item added successfully!\n";
}
void viewItems() {
    ifstream fin("inventory.txt");

    if (!fin) {
        cout << "File error!\n";
        return;
    }string name;
    int qty;
    float price;
   cout << "\nInventory:\n";
  while (fin >> name >> qty >> price) {
        cout << "Name: " << name
             << ", Qty: " << qty
             << ", Price: " << price << endl;
    }
fin.close();
}


void searchItem() {
    ifstream fin("inventory.txt");
    if (!fin) {
        cout << "File error!\n";
        return;
    }
    string search, name;
    int qty;
    float price;
    bool found = false;

    cout << "Enter item name to search: ";
    cin >> search;

    tolower(search);

    while (fin >> name >> qty >> price) {
        string temp = name;
        tolower(temp);

        if (temp == search) {
            cout << "\nItem Found:\n";
            cout << "Name: " << name
                 << ", Qty: " << qty
                 << ", Price: " << price << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Item not found!\n";
    }

    fin.close();
}
int main() {
    int choice;

    do {
        cout << "\n1. Add Item\n2. View Items\n3. Search Item\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: additem(); break;
            case 2: viewItems(); break;
            case 3: searchItem(); break;
            case 4: cout << "Exit\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
