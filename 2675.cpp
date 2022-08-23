#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, R;
    string S;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> R >> S;
        for (auto const &x : S) {
            for (int j = 0; j < R; ++j) {
                cout << x;
            }
        }
        cout << '\n';
    }
    return 0;
}
