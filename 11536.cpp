#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    if (is_sorted(vec.cbegin(), vec.cend())) {
        cout << "INCREASING";
    } else if (is_sorted(vec.cbegin(), vec.cend(), greater<string>())) {
        cout << "DECREASING";
    } else {
        cout << "NEITHER";
    }
    return 0;
}
