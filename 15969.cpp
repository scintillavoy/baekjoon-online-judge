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
    auto minmax = minmax_element(vec.begin(), vec.end());
    cout << *(minmax.second) - *(minmax.first);
    return 0;
}
