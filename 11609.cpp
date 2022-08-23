#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, string>> vec(n);
    for (auto &x : vec) {
        cin >> x.first >> x.second;
    }
    sort(vec.begin(), vec.end(),
        [](const pair<string, string> &a, const pair<string, string> &b) -> bool {
        if (a.second != b.second) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    });
    for (auto const &x : vec) {
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}
