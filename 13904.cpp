#include <iostream>
#include <vector>
#include <utility>
#include <queue>
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
        return a.first > b.first;
    });
    priority_queue<int> q;
    int score = 0;
    for (int d = vec[0].first, i = 0; d > 0; --d) {
        while (i < vec.size() && d == vec[i].first) {
            q.push(vec[i++].second);
        }
        if (!q.empty()) {
            score += q.top();
            q.pop();
        }
    }
    cout << score;
    return 0;
}
