#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    int sum = 0;
    for (auto &x : vec) {
        cin >> x;
        sum += x;
    }

    cout.precision(6);
    cout << fixed;
    cout << (double) sum / N << '\n';

    nth_element(vec.begin(), vec.begin() + vec.size() / 2, vec.end());
    double median = vec[vec.size() / 2];
    if (N % 2 == 0) {
        nth_element(vec.begin(), vec.begin() + vec.size() / 2 - 1, vec.end());
        median = (median + vec[vec.size() / 2 - 1]) / 2;
    }
    cout << median;
    return 0;
}
