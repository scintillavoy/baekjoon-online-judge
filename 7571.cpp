#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> vec(M);
    for (auto &x : vec) {
        cin >> x.first >> x.second;
    }

    pair<int, int> median;
    nth_element(vec.begin(), vec.begin() + vec.size()/2, vec.end(),
        [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
    });
    median.first = vec[vec.size()/2].first;
    nth_element(vec.begin(), vec.begin() + vec.size()/2, vec.end(),
        [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
    });
    median.second = vec[vec.size()/2].second;

    int distance = 0;
    for (auto const &x : vec) {
        distance += abs(x.first - median.first);
        distance += abs(x.second - median.second);
    }
    cout << distance;
    return 0;
}
