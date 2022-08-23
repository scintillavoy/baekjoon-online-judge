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
    nth_element(vec.begin(), vec.begin() + (vec.size() - 1) / 2, vec.end());
    cout << vec[(vec.size() - 1) / 2];
    return 0;
}
