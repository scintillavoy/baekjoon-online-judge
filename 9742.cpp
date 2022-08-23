#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string str;
    int n;
    while (cin >> str >> n) {
        cout << str << ' ' << n << " = ";
        while (--n) {
            if (!next_permutation(str.begin(), str.end())) {
                cout << "No permutation";
                break;
            }
        }
        if (n == 0) {
            cout << str;
        }
        cout << '\n';
    }
    return 0;
}
