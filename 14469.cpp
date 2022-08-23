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
        [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
    });
    int minTime = 0;
    for (auto const &x : vec) {
        if (minTime < x.first) {
            minTime = x.first + x.second;
        } else {
            minTime += x.second;
        }
    }
    cout << minTime;
    return 0;
}
