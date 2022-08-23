#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end(), [](const int &a, const int &b) {
        return abs(a) < abs(b);
    });
    int minSum = 2000000000, minA, minB;
    for (int i = 0; i < vec.size() - 1; ++i) {
        if (minSum > abs(vec[i] + vec[i+1])) {
            minSum = abs(vec[i] + vec[i+1]);
            minA = vec[i], minB = vec[i+1];
        }
    }
    if (minA > minB) {
        swap(minA, minB);
    }
    cout << minA << ' ' << minB;
    return 0;
}
