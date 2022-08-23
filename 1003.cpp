#include <iostream>
using namespace std;

int main() {
    int dp0[41] = {1, 0, }, dp1[41] = {0, 1, };
    for (int i = 2; i < 41; ++i) {
        dp0[i] = dp0[i-1] + dp0[i-2];
        dp1[i] = dp1[i-1] + dp1[i-2];
    }
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << dp0[N] << ' ' << dp1[N] << '\n';
    }
    return 0;
}
