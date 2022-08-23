#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end(), [](const int &a, const int &b) {
        return a > b;
    });
    int sum = 0;
    for (int i = 0; i < vec.size(); ++i) {
        sum += vec[i];
        if (sum >= M * K) {
            cout << i + 1;
            break;
        }
    }
    if (sum < M * K) {
        cout << "STRESS";
    }
    return 0;
}
