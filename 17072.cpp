#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> intensity(N, vector<int>(M));
    for (auto &x : intensity) {
        for (auto &y : x) {
            int R, G, B;
            cin >> R >> G >> B;
            y = 2126*R + 7152*G + 722*B;
        }
    }
    
    for (auto const &x : intensity) {
        for (auto const &y : x) {
            if (0 <= y && y < 510000) {
                cout << '#';
            } else if (510000 <= y && y < 1020000) {
                cout << 'o';
            } else if (1020000 <= y && y < 1530000) {
                cout << '+';
            } else if (1530000 <= y && y < 2040000) {
                cout << '-';
            } else if (2040000 <= y) {
                cout << '.';
            }
        }
        cout << '\n';
    }
    return 0;
}
