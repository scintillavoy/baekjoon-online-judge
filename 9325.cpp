#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int s, n;
        cin >> s >> n;
        for (int j = 0; j < n; ++j) {
            int q, p;
            cin >> q >> p;
            s += q * p;
        }
        cout << s << '\n';
    }
    return 0;
}
