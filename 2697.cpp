#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string str;
        cin >> str;
        if (!next_permutation(str.begin(), str.end())) {
            cout << "BIGGEST";
        } else {
            cout << str;
        }
        cout << '\n';
    }
    return 0;
}
