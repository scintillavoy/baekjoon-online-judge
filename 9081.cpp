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
            prev_permutation(str.begin(), str.end());
        }
        cout << str << '\n';
    }
    return 0;
}
