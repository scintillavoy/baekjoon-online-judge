#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    nth_element(vec.begin(), vec.begin() + 1, vec.end());
    cout.precision(2);
    cout << fixed << vec[1];
    return 0;
}
