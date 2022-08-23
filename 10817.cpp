#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a >= b && b >= c) || (c >= b && b >= a)) {
        cout << b;
    } else if ((c >= a && a >= b) || (b >= a && a >= c)) {
        cout << a;
    } else {
        cout << c;
    }
    return 0;
}
