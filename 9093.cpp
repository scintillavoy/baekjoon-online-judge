#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (T--) {
        string sentence, word;
        getline(cin, sentence);
        istringstream iss(sentence);
        iss >> word;
        reverse(word.begin(), word.end());
        cout << word;
        while (iss >> word) {
            reverse(word.begin(), word.end());
            cout << ' ' << word;
        }
        cout << '\n';
    }
    return 0;
}
