#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 1; i <= N; ++i) {
        string sentence, word;
        getline(cin, sentence);
        istringstream iss(sentence);
        vector<string> words;
        while (iss >> word) {
            words.push_back(word);
        }
        cout << "Case #" << i << ':';
        for (auto it = words.crbegin(); it != words.crend(); ++it) {
            cout << ' ' << *it;
        }
        cout << '\n';
    }
    return 0;
}
