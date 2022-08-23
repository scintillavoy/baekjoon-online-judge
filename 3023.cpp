#include <iostream>
#include <vector>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> vec(R, vector<char>(C));
    for (auto &row : vec) {
        for (auto &x : row) {
            cin >> x;
        }
    }
    int A, B;
    cin >> A >> B;

    for (auto &row : vec) {
        for (int i = row.size() - 1; i >= 0; --i) {
            row.push_back(row[i]);
        }
    }
    for (int i = vec.size() - 1; i >= 0; --i) {
        vec.push_back(vec[i]);
    }
    vec[A-1][B-1] = (vec[A-1][B-1] == '.' ? '#' : '.');

    for (auto const &row : vec) {
        for (auto const &x : row) {
            cout << x;
        }
        cout << '\n';
    }
    return 0;
}
