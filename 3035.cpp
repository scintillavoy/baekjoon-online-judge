#include <iostream>
#include <vector>
using namespace std;

int main() {
    int R, C, ZR, ZC;
    cin >> R >> C >> ZR >> ZC;
    vector<vector<char>> vec(R, vector<char>(C));
    for (auto &row : vec) {
        for (auto &c : row) {
            cin >> c;
        }
    }
    for (auto &row : vec) {
        for (int i = 0; i < ZR; ++i) {
            for (auto &c : row) {
                for (int j = 0; j < ZC; ++j) {
                    cout << c;
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
