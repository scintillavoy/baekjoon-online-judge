#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, pair<int, int>> m;
    for (int i = 0; i < n; ++i) {
        string judge;
        cin >> judge;
        if (m.count(judge)) {
            ++m[judge].first;
        } else {
            m[judge] = make_pair(1, 0);
        }
    }
    for (int i = 0; i < n; ++i) {
        string judge;
        cin >> judge;
        if (m.count(judge)) {
            ++m[judge].second;
        } else {
            m[judge] = make_pair(0, 1);
        }
    }
    int answer = 0;
    for (auto const &x : m) {
        answer += min(x.second.first, x.second.second);
    }
    cout << answer;
    return 0;
}
