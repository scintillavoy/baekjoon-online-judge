#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    vector< pair<int, int> > vec;
    for (int i = 1; i <= 8; ++i) {
        int score;
        cin >> score;
        vec.emplace_back(i, score);
    }

    sort(vec.begin(), vec.end(),
        [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        }
    );
    int sum = 0;
    for (auto it = vec.cbegin(); it != vec.cbegin() + 5; ++it) {
        sum += it->second;
    }
    cout << sum << '\n';

    sort(vec.begin(), vec.begin() + 5,
        [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
        }
    );
    for (auto it = vec.cbegin(); it != vec.cbegin() + 5; ++it) {
        cout << it->first << ' ';
    }

    return 0;
}
