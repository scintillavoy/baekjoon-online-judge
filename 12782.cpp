#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string N, M;
        cin >> N >> M;
        int diff1 = abs(count(N.begin(), N.end(), '0') -
                        count(M.begin(), M.end(), '0'));
        int diff2 = -diff1;
        for (int i = 0; i < N.size(); ++i) {
            if (N[i] != M[i]) {
                ++diff2;
            }
        }
        cout << diff1 + (diff2 + 1) / 2 << '\n';
    }
    return 0;
}
