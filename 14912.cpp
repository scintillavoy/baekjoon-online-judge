#include <iostream>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int cnt[10] = {0};
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j > 0; j /= 10) {
            ++cnt[j % 10];
        }
    }
    cout << cnt[d];
    return 0;
}
