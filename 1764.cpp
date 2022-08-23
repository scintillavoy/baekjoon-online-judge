#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // input
    int N, M;
    cin >> N >> M;
    vector<string> vec1(N), vec2(M);
    for (auto &x : vec1) {
        cin >> x;
    }
    for (auto &x : vec2) {
        cin >> x;
    }

    // compute
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    vector<string> res;
    for (int i = 0, j = 0; i < vec1.size() && j < vec2.size();) {
        if (vec1[i] < vec2[j]) {
            ++i;
        } else if (vec1[i] > vec2[j]) {
            ++j;
        } else {
            res.push_back(vec1[i]);
            ++i, ++j;
        }
    }

    // output
    cout << res.size() << '\n';
    for (auto const &x : res) {
        cout << x << '\n';
    }
    return 0;
}
