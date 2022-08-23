#include <iostream>
using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        if (!n && !k) {
            break;
        }
        if (k > n - k) {
            k = n - k;
        }
        long long answer = 1;
        for (int i = 1; i <= k; ++i) {
            answer = answer * (n - i + 1) / i;
        }
        cout << answer << '\n';
    }
    return 0;
}
