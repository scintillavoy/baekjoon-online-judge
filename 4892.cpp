#include <iostream>
using namespace std;

int main() {
    for (int n0, i = 1; cin >> n0; ++i) {
        if (n0 == 0) {
            break;
        }
        cout << i << ". " << (n0 % 2 ? "odd" : "even") << ' ';
        cout << (n0 * 3 + 1) / 6 << '\n';
    }
    return 0;
}
