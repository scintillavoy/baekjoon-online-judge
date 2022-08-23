#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> v1(N);
        for (auto &x : v1) {
            cin >> x;
        }
        sort(v1.begin(), v1.end());
        cin >> N;
        vector<int> v2(N);
        for (auto &x : v2) {
            cin >> x;
        }
        sort(v2.begin(), v2.end());
        int minDiff = 1000000;
        for (int i = 0, j = 0; i < v1.size() && j < v2.size();) {
            if (minDiff > abs(v1[i] - v2[j])) {
                minDiff = abs(v1[i] - v2[j]);
            }
            if (v1[i] < v2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        cout << minDiff << '\n';
    }
    return 0;
}
