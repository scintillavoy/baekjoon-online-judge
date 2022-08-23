#include <iostream>
#include <string>
using namespace std;

int main() {
    string N;
    cin >> N;
    for (int i = 1; i < N.size(); ++i) {
        int a = 1, b = 1;
        for (auto const &x : N.substr(0, i)) {
            a *= x - '0';
        }
        for (auto const &x : N.substr(i)) {
            b *= x - '0';
        }
        if (a == b) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
