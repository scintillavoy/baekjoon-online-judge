#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        int val1 = 0, val2 = stoi(str.substr(4, 4));
        for (int j = 0; j < 3; ++j) {
            val1 *= 26;
            val1 += str[j] - 'A';
        }
        if (abs(val1 - val2) <= 100) {
            cout << "nice\n";
        } else {
            cout << "not nice\n";
        }
    }
    return 0;
}
