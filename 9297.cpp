#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int n, d;
        cin >> n >> d;
        cout << "Case " << i << ':';
        if (!n) {
            cout << ' ' << 0;
        } else {
            if (n / d) {
                cout << ' ' << n / d;
            }
            if (n % d) {
                cout << ' ' << n % d << '/' << d;
            }
        }
        cout << '\n';
    }
    return 0;
}
