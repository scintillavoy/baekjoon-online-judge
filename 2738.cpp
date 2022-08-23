#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> vec(N, vector<int>(M));
    for (auto &row : vec) {
        for (auto &x : row) {
            cin >> x;
        }
    }
    for (auto &row : vec) {
        for (auto &x : row) {
            int num;
            cin >> num;
            cout << x + num << ' ';
        }
        cout << '\n';
    }
    return 0;
}
