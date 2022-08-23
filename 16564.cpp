#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i < N; ++i) {
        K -= (vec[i] - vec[0]) * i;
        vec[0] = vec[i];
        if (K < 0) {
            vec[0] += (K - i + 1) / i;
            break;
        }
    }
    if (K > 0) {
        vec[0] += K / N;
    }
    cout << vec[0] << '\n';
    return 0;
}
