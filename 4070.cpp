#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    for (int t = 1; cin >> n >> k; ++t) {
        if (!n && !k) {
            break;
        }
        vector<string> vec(n);
        for (auto &x : vec) {
            cin >> x;
        }
        sort(vec.begin(), vec.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        bool check = true;
        for (int i = 0; i < vec.size(); i += k) {
            double avg = 0;
            for (int j = 0; j < k; ++j) {
                avg += vec[i+j].size();
            }
            avg /= k;
            for (int j = 0; j < k; ++j) {
                if (abs(vec[i+j].size() - avg) > 2) {
                    check = false;
                }
            }
        }
        cout << "Case " << t << ": " << (check ? "yes" : "no") << "\n\n";
    }
    return 0;
}
