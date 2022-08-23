#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> vec(N, 0);
    while (M--) {
        int i, j, k;
        cin >> i >> j >> k;
        for (; i <= j; ++i) {
            vec[i - 1] = k;
        }
    }
    for (auto const &x : vec) {
        cout << x << ' ';
    }
    return 0;
}
