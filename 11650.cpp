#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector< pair<int, int> > vec(N);
    for (auto &p : vec) {
        cin >> p.first >> p.second;
    }
    sort(vec.begin(), vec.end(),
        [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second < b.second;
            }
    });
    for (auto const &p : vec) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}
