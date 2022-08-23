#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> vec(N);
    for (int last = 0, i = 0; i < N; ++i) {
        cin >> vec[i];
        last += vec[i];
        vec[i] = last - 1;
    }
    while (Q--) {
        int query;
        cin >> query;
        cout << lower_bound(vec.begin(), vec.end(), query) - vec.begin() + 1;
        cout << '\n';
    }
    return 0;
}
