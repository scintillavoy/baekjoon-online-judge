#include <iostream>
#include <utility>
#include <bitset>
using namespace std;

int main() {
    int N;
    cin >> N;
    bitset<4> check(0b1000);
    while (N--) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        if (a == 1) {
            if (b == 3) {
                check.set(0);
            } else if (b == 4) {
                check.set(1);
            } else {
                check.reset(3);
            }
        } else if (a == 3 && b == 4) {
            check.set(2);
        } else {
            check.reset(3);
        }
    }
    cout << (check.all() ? "Wa-pa-pa-pa-pa-pa-pow!" : "Woof-meow-tweet-squeek");
    cout << '\n';
    return 0;
}
