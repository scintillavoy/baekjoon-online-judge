#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> vec(N);
    for (auto &x : vec) {
        cin >> x.first >> x.second;
    }

    sort(vec.begin(), vec.end(),
        [](const pair<int, int> &a, const pair <int, int> &b) -> bool {
            return a.first < b.first;
    });
    int last = 0, length = 0;
    for (auto const &x : vec) {
        if (x.second > last) {
            length += (x.second - last) - max(x.first - last, 0);
            last = x.second;
        }
    }

    cout << length << '\n';
    return 0;
}
