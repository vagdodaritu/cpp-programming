#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, value;

    set<int> numbers;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        numbers.insert(value);
    }

    cout << "\nUnique elements in sorted order:\n";


    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}
