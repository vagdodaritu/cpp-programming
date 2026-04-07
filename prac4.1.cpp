#include <iostream>
using namespace std;


void display(int* arr, int size) {
    if (size == 0) {
        cout << "array is empty\n";
        return;
    }

    cout << "array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void insertend(int*& arr, int& size, int value) {
    int* newarr = new int[size + 1];

    for (int i = 0; i < size; i++) {
        newarr[i] = arr[i];
    }

    newarr[size] = value;

    delete[] arr;
    arr = newarr;
    size++;
}


void deleteat(int*& arr, int& size, int pos) {
    if (size == 0) {
        cout << "array is empty\n";
        return;
    }

    if (pos < 0 || pos >= size) {
        cout << "invalid position\n";
        return;
    }

    int* newarr = new int[size - 1];

    for (int i = 0, j = 0; i < size; i++) {
        if (i != pos) {
            newarr[j++] = arr[i];
        }
    }

    delete[] arr;
    arr = newarr;
    size--;
}

int main() {
    int* arr = nullptr;
    int size = 0;
    int choice, value, pos;

    do {

        cout << "1. Insert at end\n";
        cout << "2. Delete at position\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "enter value: ";
                cin >> value;
                insertend(arr, size, value);
                break;

            case 2:
                cout << "enter position : ";
                cin >> pos;
                deleteat(arr, size, pos);
                break;

            case 3:
                display(arr, size);
                break;

            case 4:
                cout << "Exit\n";
                break;

            default:
                cout << "invalid choice\n";
        }

    } while (choice != 4);

    delete[] arr;
    return 0;
}
