#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < T; ++i) {
        string msg, rule;
        getline(cin, msg);
        getline(cin, rule);
        for (auto const &x : msg) {
            if (x == ' ') {
                cout << ' ';
            } else {
                cout << rule[x - 'A'];
            }
        }
        cout << '\n';
    }
    return 0;
}
