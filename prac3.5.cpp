#include <iostream>
using namespace std;

long long superdigit(long long n) {
    if (n < 10)
        return n;

    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return superdigit(sum);
}

int main() {
    string n = "9875";
    int k = 4;


    long long initialsum = 0;
    for (char c : n) {
        initialsum += c - '0';
    }


    long long newnumber = initialsum * k;


    cout << "Super Digit: " << superdigit(newnumber);

    return 0;
}
