#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int minCost = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (i % 3 != 2) {
            minCost += vec[i];
        }
    }
    cout << minCost;
    return 0;
}
