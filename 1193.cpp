#include <iostream>
#include <utility>
using namespace std;

int main() {
    int X, a = 1, b = 1;
    for (cin >> X; X > 1; --X) {
        if (b == 1) {
            swap(a, b);
            ++b;
        } else {
            ++a;
            --b;
        }
    }
    if ((a + b) % 2) {
        cout << a << '/' << b;
    } else {
        cout << b << '/' << a;
    }
    return 0;
}
