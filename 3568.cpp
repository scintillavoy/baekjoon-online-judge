#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    istringstream iss(str);
    string basic, word;
    iss >> basic;
    while (iss >> word) {
        cout << basic;
        word.pop_back();
        while (!isalpha(word.back())) {
            if (word.back() == ']') {
                cout << "[]";
                word.pop_back();
            } else {
                cout << word.back();
            }
            word.pop_back();
        }
        cout << ' ' << word << ";\n";
    }
    return 0;
}
