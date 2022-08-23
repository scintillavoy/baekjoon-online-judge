#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int xi_min, xi_max, location;
        cin >> location;
        xi_min = xi_max = location;
        for (int j = 1; j < n; ++j) {
            cin >> location;
            if (location < xi_min) {
                xi_min = location;
            } else if (location > xi_max) {
                xi_max = location;
            }
        }
        cout << (xi_max - xi_min) * 2 << '\n';
    }
    return 0;
}
