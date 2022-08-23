#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end(), [](const string &a, const string &b) -> bool {
        if (a.size() != b.size()) {
            return a.size() < b.size();
        } else {
            return a < b;
        }
    });
    cout << vec[0] << '\n';
    for (int i = 1; i < N; ++i) {
        if (vec[i] != vec[i - 1]) {
            cout << vec[i] << '\n';
        }
    }
    return 0;
}
