#include <iostream>
using namespace std;

int main() {
    int a[3];
    while (cin >> a[0] >> a[1] >> a[2]) {
        if (!a[0] && !a[1] && !a[2]) {
            break;
        }
        if (a[1] - a[0] == a[2] - a[1]) {
            cout << "AP " << a[2] + a[2] - a[1];
        } else if (a[1] / a[0] == a[2] / a[1]) {
            cout << "GP " << a[2] * a[2] / a[1];
        }
        cout << '\n';
    }
    return 0;
}
