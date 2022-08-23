#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[3];
    while (cin >> a[0] >> a[1] >> a[2]) {
        if (!a[0] && !a[1] && !a[2]) {
            break;
        }
        sort(a, a + 3);
        if (a[0] + a[1] <= a[2]) {
            cout << "Invalid";
        } else if (a[0] == a[2]) {
            cout << "Equilateral";
        } else if (a[0] == a[1] || a[1] == a[2]) {
            cout << "Isosceles";
        } else {
            cout << "Scalene";
        }
        cout << '\n';
    }
    return 0;
}
