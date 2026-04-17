#include <iostream>
#include <string>
using namespace std;

void tolowercase(string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
    }
}
}

int main() {
    string paragraph;

    cout << "Enter a paragraph:\n";
    getline(cin, paragraph);

    string words[1000];
    int freq[1000] = {0};
    int count = 0;

    string temp = "";


    for (int i = 0; i <= paragraph.length(); i++) {
        if (paragraph[i] == ' ' || paragraph[i] == '\0') {
            if (temp != "") {
                tolowercase(temp);


                bool found = false;
                for (int j = 0; j < count; j++) {
                    if (words[j] == temp) {
                        freq[j]++;
                        found = true;
                        break;
                    }
                }if (!found) {
                    words[count] = temp;
                    freq[count] = 1;
                    count++;}
                    temp = "";
            }
        } else {temp += paragraph[i];
        }
    }

for (int i = 0; i < count; i++) {
cout << words[i] << " : " << freq[i] << endl;
    }
return 0;
}
