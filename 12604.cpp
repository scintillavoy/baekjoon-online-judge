#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int C, I;
    cin >> C >> I;
    vector<int> price(I);
    for (auto &x : price) {
        cin >> x;
    }
    for (int m = 0; m < I - 1; ++m) {
        for (int n = m + 1; n < I; ++n) {
            if (price[m] + price[n] == C) {
                cout << m + 1 << " " << n + 1 << '\n';
                return;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
