#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> vec(M);
    for (auto &x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int minPrice = 1000000, maxProfit = 0;
    for (int i = 0; i < N && i < M; ++i) {
        if (maxProfit < (i + 1) * vec[i]) {
            maxProfit = (i + 1) * vec[i];
            minPrice = vec[i];
        }
    }
    cout << minPrice << ' ' << maxProfit;
    return 0;
}
