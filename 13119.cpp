#include <iostream>
#include <vector>
using namespace std;

int main() {
    // input
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> mountain(M);
    for (auto &x : mountain) {
        cin >> x;
    }

    vector<vector<char>> vec(N, vector<char>(M, '.'));

    // draw mountain
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < mountain[i]; ++j) {
            vec[N-1-j][i] = '#';
        }
    }

    // draw highway
    for (int i = 0; i < M; ++i) {
        vec[N-X][i] = (vec[N-X][i] == '#' ? '*' : '-');
    }

    // draw pier
    for (int i = 2; i < M; i += 3) {
        for (int j = X-1; j > mountain[i]; --j) {
            vec[N-j][i] = '|';
        }
    }

    // output
    for (auto const &row : vec) {
        for (auto const &x : row) {
            cout << x;
        }
        cout << '\n';
    }
    return 0;
}
