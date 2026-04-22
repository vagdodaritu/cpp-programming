#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    vector<int> v;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }


    vector<int> v1 = v;
    reverse(v1.begin(), v1.end());

    cout << "\nReversed using std::reverse(): ";
    for(auto it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }


    vector<int> v2 = v;
    auto start = v2.begin();
    auto end = v2.end() - 1;

    while(start < end) {
        swap(*start, *end);
        start++;
        end--;
    }

    cout << "\nReversed manually using iterators: ";
    for(auto it = v2.begin(); it != v2.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}
