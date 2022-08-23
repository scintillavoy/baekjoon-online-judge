#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
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
            int sumA = 0, sumB = 0;
            for (auto const &x : a) {
                if (isdigit(x)) {
                    sumA += x - '0';
                }
            }
            for (auto const &x : b) {
                if (isdigit(x)) {
                    sumB += x - '0';
                }
            }
            if (sumA != sumB) {
                return sumA < sumB;
            } else {
                return a < b;
            }
        }
    });
    for (auto const &x : vec) {
        cout << x << '\n';
    }
    return 0;
}
