#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 10; i < x; i *= 10) {
            if (x % i >= i / 2) {
                x += i - x % i;
            } else {
                x -= x % i;
            }
        }
        cout << x << '\n';
    }
    return 0;
}
