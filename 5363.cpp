#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < N; ++i) {
        string word1, word2, rest;
        getline(cin, word1, ' ');
        getline(cin, word2, ' ');
        getline(cin, rest);
        cout << rest << ' ' << word1 << ' ' << word2 << '\n';
    }
    return 0;
}
