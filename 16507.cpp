#include <iostream>
#include <vector>
using namespace std;

int main() {
    int R, C, Q;
    cin >> R >> C >> Q;

    vector<vector<int>> vec(R + 1, vector<int>(C + 1, 0));
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> vec[i][j];
            vec[i][j] += vec[i-1][j] + vec[i][j-1] - vec[i-1][j-1];
        }
    }

    while (Q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << (vec[r2][c2] - vec[r2][c1-1] - vec[r1-1][c2] + vec[r1-1][c1-1]) /
                ((r2-r1+1)*(c2-c1+1)) << '\n';
    }

    return 0;
}
