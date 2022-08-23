#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> vec(N);
    for (auto &x : vec) {
        cin >> x.first >> x.second;
    }
    sort(vec.begin(), vec.end(),
        [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
            if (a.second != b.second) {
                return a.second < b.second;
            } else {
                return a.first < b.first;
            }
    });
    int endTime = 0, cnt = 0;
    for (auto const &x : vec) {
        if (x.first >= endTime) {
            endTime = x.second;
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
