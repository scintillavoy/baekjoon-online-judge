#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

int main() {
    int n, num;
    vector<int> vec;
    cin >> n;
    for (; n > 0; --n) {
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());
    int median = vec[vec.size() / 2];
    int range = vec.back() - vec.front();
    
    // compute average
    double average = 0;
    for (auto const &x : vec) {
        average += x;
    }
    average = floor(average / vec.size() + 0.5);

    // compute mode
    int mode;
    vector<pair<int, int>> cnt = {pair<int, int>(vec.front(), 0)};
    for (auto const &x : vec) {
        if (x == cnt.back().first) {
            ++cnt.back().second;
        } else {
            cnt.push_back(pair<int, int>(x, 1));
        }
    }
    sort(cnt.begin(), cnt.end(),
        [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
    });
    if ((cnt.size() >= 1) && (cnt[0].second == cnt[1].second)) {
        mode = cnt[1].first;
    } else {
        mode = cnt[0].first;
    }

    cout << average << '\n' << median << '\n'
         << mode << '\n' << range << '\n';
    return 0;
}
