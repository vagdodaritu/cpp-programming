#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    map<string, int> wordCount;

    stringstream ss(sentence);
    string word;


    while (ss >> word) {
        wordCount[word]++;
    }

    cout << "\nWord Frequency:\n";


    for (auto it : wordCount) {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}
