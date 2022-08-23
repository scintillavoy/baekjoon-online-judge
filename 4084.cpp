#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        if (!a && !b && !c && !d) {
            break;
        }
        int cnt;
        for (cnt = 0; a != b || b != c || c != d; ++cnt) {
            int temp = a;
            a = abs(a - b);
            b = abs(b - c);
            c = abs(c - d);
            d = abs(d - temp);
        }
        cout << cnt << '\n';
    }
    return 0;
}
