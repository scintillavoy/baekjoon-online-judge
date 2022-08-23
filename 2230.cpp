#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end());
    int minDiff = 2000000000;
    for (auto it1 = vec.begin(), it2 = vec.begin(); it2 != vec.end();) {
        if (abs(*it1 - *it2) >= M) {
            if (minDiff > abs(*it1 - *it2)) {
                minDiff = abs(*it1 - *it2);
            }
            if (it1 == it2) {
                break;
            }
            ++it1;
        } else {
            ++it2;
        }
    }
    cout << minDiff;
    return 0;
}
