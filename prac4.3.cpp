#include <iostream>
using namespace std;


int* mergearrays(int* a, int n, int* b, int m) {
    int* merged = new int[n + m];

    int i = 0, j = 0, k = 0;


    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }


    while (i < n) {
        merged[k++] = a[i++];
    }


    while (j < m) {
        merged[k++] = b[j++];
    }

    return merged;
}


void display(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;

    cout << "enter size of first sorted array: ";
    cin >> n;

    int* a = new int[n];

    cout << "enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "enter size of second sorted array: ";
    cin >> m;

    int* b = new int[m];

    cout << "enter " << m << " sorted elements:\n";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }


    int* merged = mergearrays(a, n, b, m);

    cout << "merged sorted array: ";
    display(merged, n + m);


    delete[] a;
    delete[] b;
    delete[] merged;

    return 0;
}
