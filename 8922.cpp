#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (auto &x : vec) {
            cin >> x;
        }
        set<vector<int>> s;
        s.insert(vec);
        while (true) {
            int temp = vec[0];
            for (int i = 0; i < n - 1; ++i) {
                vec[i] = abs(vec[i] - vec[i+1]);
            }
            vec[n-1] = abs(vec[n-1] - temp);
            if (vec == vector<int>(n, 0)) {
                cout << "ZERO\n";
                break;
            } else if (s.count(vec)) {
                cout << "LOOP\n";
                break;
            } else {
                s.insert(vec);
            }
        }
    }
    return 0;
}
