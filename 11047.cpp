#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    int cnt = 0;
    for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
        cnt += K / *it;
        K %= *it;
    }
    cout << cnt;
    return 0;
}
