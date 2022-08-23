#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int a, b;
        string str;
        cin >> a >> b >> str;
        for (auto const &x : str) {
            cout << char((a * (x - 'A') + b) % 26 + 'A');
        }
        cout << '\n';
    }
    return 0;
}
