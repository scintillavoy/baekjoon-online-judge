#include <iostream>
using namespace std;

int main() {
    int arr[100][100] = {0};
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j <= x2; ++j) {
            for (int k = y1; k <= y2; ++k) {
                ++arr[j-1][k-1];
            }
        }
    }
    int cnt = 0;
    for (auto const &row : arr) {
        for (auto const &elem : row) {
            if (elem > M) {
                ++cnt;
            }
        }
    }
    cout << cnt;
    return 0;
}
