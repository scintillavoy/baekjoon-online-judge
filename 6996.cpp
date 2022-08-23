#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string a, b;
        cin >> a >> b;
        cout << a << " & " << b << " are ";
        if (!is_permutation(a.begin(), a.end(), b.begin(), b.end())) {
            cout << "NOT ";
        }
        cout << "anagrams.\n";
    }
    return 0;
}
