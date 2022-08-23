#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Scenario #" << i << ":\n";
        int m;
        cin >> m;
        vector<string> vec(m);
        for (auto &x : vec) {
            cin >> x;
        }
        int n;
        cin >> n;
        while (n--) {
            int k;
            cin >> k;
            while (k--) {
                int idx;
                cin >> idx;
                cout << vec[idx];
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
