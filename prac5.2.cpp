#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("input.txt");

   if (!file) {
        cerr << "error: file could not be opened!" << endl;
        return 1;
    }

    char ch;
    int characters = 0, words = 0, lines = 0;
    bool inWord = false;


    while (file.get(ch)) {
        characters++;


if (ch == '\n') {
lines++;
        }
if (ch == ' ' || ch == '\n' || ch == '\t') {
if (inWord) {
                words++;
                inWord = false;
}} else {
    inWord = true;
        }
    }if (inWord) {
        words++;
    }
    if (characters > 0) {
        lines++;
    }file.close();
cout << "characters: " << characters << endl;
cout << "words: " << words << endl;
cout << "lines: " << lines << endl;

    return 0;
}
