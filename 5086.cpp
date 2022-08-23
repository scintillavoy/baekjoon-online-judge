#include <iostream>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        if (!a && !b) {
            break;
        }
        if (b % a == 0) {
            cout << "factor";
        } else if (a % b == 0) {
            cout << "multiple";
        } else {
            cout << "neither";
        }
        cout << '\n';
    }
    return 0;
}
