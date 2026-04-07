#include <iostream>
#include <ctime>
using namespace std;


int iterativesum(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}


int recursivesum(int arr[], int n) {
    if(n == 0)
        return 0;
    return arr[n-1] + recursivesum(arr, n-1);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    clock_t start1 = clock();
    int sum1 = iterativesum(arr, n);
    clock_t end1 = clock();


    clock_t start2 = clock();
    int sum2 = recursivesum(arr, n);
    clock_t end2 = clock();

    cout << "iterative sum: " << sum1;
    cout << "recursive sum: " << sum2;

    double time1 = double(end1 - start1) / CLOCKS_PER_SEC;
    double time2 = double(end2 - start2) / CLOCKS_PER_SEC;

    cout << "time iterative: " << time1 << " sec";
    cout << "time recursive: " << time2 << " sec";

    delete[] arr;

    return 0;
}
