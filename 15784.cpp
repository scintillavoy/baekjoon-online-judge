#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, a, b;
    cin >> N >> a >> b;
    vector<vector<int>> vec(N, vector<int>(N));
    for (auto &row : vec) {
        for (auto &x : row) {
            cin >> x;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (vec[a-1][i] > vec[a-1][b-1] || vec[i][b-1] > vec[a-1][b-1]) {
            cout << "ANGRY";
            return 0;
        }
    }
    cout << "HAPPY";
    return 0;
}
