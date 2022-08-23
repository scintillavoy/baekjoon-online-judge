#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    nth_element(vec.begin(), vec.begin() + K - 1, vec.end());
    cout << vec[K - 1];
    return 0;
}
