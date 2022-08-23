#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        vec[i] = i + 1;
    }
    do {
        for (auto const &x : vec) {
            cout << x << ' ';
        }
        cout << '\n';
    } while (next_permutation(vec.begin(), vec.end()));
    return 0;
}
