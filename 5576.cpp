#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int W[10], K[10];
    for (auto &x : W) {
        cin >> x;
    }
    for (auto &x : K) {
        cin >> x;
    }
    sort(W, W + 10);
    sort(K, K + 10);
    cout << W[7] + W[8] + W[9] << ' ' << K[7] + K[8] + K[9];
    return 0;
}
