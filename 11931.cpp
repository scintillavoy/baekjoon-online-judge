#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end(),
        [](const int &a, const int &b) { return a > b; });
    for (auto const &x : vec) {
        cout << x << '\n';
    }
    return 0;
}
