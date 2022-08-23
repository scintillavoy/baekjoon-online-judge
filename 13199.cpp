#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int P, M, F, C;
        cin >> P >> M >> F >> C;
        int coupon = M / P * C, bonus = 0;
        coupon = coupon % F + coupon / F * C;
        while (coupon >= F) {
            bonus += coupon / F;
            coupon = coupon % F + coupon / F * C;
        }
        cout << bonus << '\n';
    }
    return 0;
}
