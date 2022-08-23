#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec;
    vec.reserve(n);
    for (int i = 2; i <= n; ++i) {
        vec.push_back(i);
        push_heap(vec.begin(), vec.end());
    }
    vec.push_back(1);
    for (auto const &x : vec) {
        cout << x << ' ';
    }
    return 0;
}
