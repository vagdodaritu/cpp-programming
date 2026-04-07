#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    int itemID;
    string itemName;
    double price;
    int quantity;

public:
    void inputItem();
    int getItemID() const;
    void addStock(int amount);
    bool validateSale(int amount);
    void sellItem(int amount);
    void displayItem() const;
    void showStock() const;
};
void Item::inputItem() {
    cout << "\nEnter Item ID: ";
    cin >> itemID;

    cout << "Enter Item Name: ";
    cin.ignore();
    getline(cin, itemName);

    cout << "Enter Price: ";
    cin >> price;

    cout << "Enter Quantity: ";
    cin >> quantity;
}

int Item::getItemID() const {
    return itemID;
}

void Item::addStock(int amount) {
    if (amount > 0) {
        quantity += amount;
        cout << "Stock added successfully.\n";
    } else {
        cout << "Invalid quantity!\n";
    }
}

bool Item::validateSale(int amount) {
    if (amount <= 0) {
        cout << "Invalid sale quantity!\n";
        return false;
    }
    if (amount > quantity) {
        cout << "Insufficient stock!\n";
        return false;
    }
    return true;
}

void Item::sellItem(int amount) {
    if (validateSale(amount)) {
        quantity -= amount;
        cout << "Item sold successfully.\n";
    }
}

void Item::displayItem() const {
    cout << "\n------------------------";
    cout << "\nItem ID: " << itemID;
    cout << "\nName: " << itemName;
    cout << "\nPrice: $" << price;
    cout << "\nQuantity in Stock: " << quantity;
    cout << "\n------------------------\n";
}

void Item::showStock() const {
    cout << "\nItem Name: " << itemName;
    cout << "\nAvailable Stock: " << quantity << endl;
}

int findItemByID(Item catalog[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (catalog[i].getItemID() == id)
            return i;
    }
    return -1;
}


int main() {
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    Item* catalog = new Item[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEntering details for Item " << i + 1;
        catalog[i].inputItem();
    }

    int choice, id, amount, index;

    do {
        cout << "\n===== Inventory Management System =====\n";
        cout << "1. Display All Items\n";
        cout << "2. Add Stock\n";
        cout << "3. Sell Item\n";
        cout << "4. Check Stock\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            for (int i = 0; i < n; i++) {
                catalog[i].displayItem();
            }
            break;

        case 2:
            cout << "Enter Item ID: ";
            cin >> id;
            index = findItemByID(catalog, n, id);
            if (index != -1) {
                cout << "Enter quantity to add: ";
                cin >> amount;
                catalog[index].addStock(amount);
            } else {
                cout << "Item not found!\n";
            }
            break;

        case 3:
            cout << "Enter Item ID: ";
            cin >> id;
            index = findItemByID(catalog, n, id);
            if (index != -1) {
                cout << "Enter quantity to sell: ";
                cin >> amount;
                catalog[index].sellItem(amount);
            } else {
                cout << "Item not found!\n";
            }
            break;

        case 4:
            cout << "Enter Item ID: ";
            cin >> id;
            index = findItemByID(catalog, n, id);
            if (index != -1) {
                catalog[index].showStock();
            } else {
                cout << "Item not found!\n";
            }
            break;

        case 5:
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    delete[] catalog;

    return 0;
}
