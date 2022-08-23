#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    int check[3][100] = {0};
    vector<vector<int>> num(N, vector<int>(3));
    for (auto &p : num) {
        for (int i = 0; i < 3; ++i) {
            cin >> p[i];
            ++check[i][p[i]-1];
        }
    }
    for (auto const &p : num) {
        int score = 0;
        for (int i = 0; i < 3; ++i) {
            if (check[i][p[i]-1] < 2) {
                score += p[i];
            }
        }
        cout << score << '\n';
    }
    return 0;
}
