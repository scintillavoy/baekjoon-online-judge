#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<long long> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end());
    int maxCnt = 0, cnt = 0;
    long long num = 0, prev = vec[0];
    for (auto const &x : vec) {
        if (x == prev) {
            ++cnt;
        } else {
            if (cnt > maxCnt) {
                maxCnt = cnt;
                num = prev;
            }
            cnt = 1;
            prev = x;
        }
    }
    if (cnt > maxCnt) {
        num = prev;
    }
    cout << num;
    return 0;
}
