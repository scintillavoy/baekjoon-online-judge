#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        cout << "Pairs for " << n << ":";
        if (n > 2) {
            cout << " 1 " << n - 1;
        }
        for (int j = 2; j < (n + 1) / 2; ++j) {
            cout << ", " << j << ' ' << n - j;
        }
        cout << '\n';
    }
    return 0;
}
