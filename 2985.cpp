#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    char op = 0;
    if (a + b == c) {
        op = '+';
    } else if (a - b == c) {
        op = '-';
    } else if (a * b == c) {
        op = '*';
    } else if (a / b == c && a % b == 0) {
        op = '/';
    }

    if (op) {
        cout << a << op << b << '=' << c;
    } else {
        if (a == b + c) {
            op = '+';
        } else if (a == b - c) {
            op = '-';
        } else if (a == b * c) {
            op = '*';
        } else if (a == b / c && b % c == 0) {
            op = '/';
        }
        cout << a << '=' << b << op << c;
    }
    return 0;
}
