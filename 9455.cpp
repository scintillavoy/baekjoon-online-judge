#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        // input
        int m, n;
        cin >> m >> n;
        vector< vector<int> > vec(m, vector<int>(n));
        for (auto &row : vec) {
            for (auto &elem : row) {
                cin >> elem;
            }
        }

        // output
        int dist = 0;
        for (int j = 0; j < n; ++j) {
            int cnt = -1;
            for (int k = m - 1; k >= 0; --k) {
                if (vec[k][j] == 1) {
                    ++cnt;
                    dist += m - 1 - k - cnt;
                }
            }
        }
        cout << dist << '\n';
    }
    return 0;
}
