#include <iostream>
using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        int chicken = 0;
        while (n >= k) {
            chicken += k;
            n -= k;
            ++n;
        }
        cout << chicken + n << '\n';
    }
    return 0;
}
