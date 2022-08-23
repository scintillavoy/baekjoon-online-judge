#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    if (next_permutation(vec.begin(), vec.end())) {
        for (auto const &x : vec) {
            cout << x << ' ';
        }
    } else {
        cout << "-1";
    }
    return 0;
}
