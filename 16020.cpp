#include <cstdio>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<vector<int>> vec(N, vector<int>(N));
    int minVal = numeric_limits<int>::max();
    for (auto &row : vec) {
        for (auto &x : row) {
            scanf("%d", &x);
            if (minVal > x) {
                minVal = x;
            }
        }
    }
    if (minVal == vec[0][0]) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                printf("%d ", vec[i][j]);
            }
            printf("\n");
        }
    } else if (minVal == vec[0][N-1]) {
        for (int i = N-1; i >= 0; --i) {
            for (int j = 0; j < N; ++j) {
                printf("%d ", vec[j][i]);
            }
            printf("\n");
        }
    } else if (minVal == vec[N-1][N-1]) {
        for (int i = N-1; i >= 0; --i) {
            for (int j = N-1; j >= 0; --j) {
                printf("%d ", vec[i][j]);
            }
            printf("\n");
        }
    } else if (minVal == vec[N-1][0]) {
        for (int i = 0; i < N; ++i) {
            for (int j = N-1; j >= 0; --j) {
                printf("%d ", vec[j][i]);
            }
            printf("\n");
        }
    }
    return 0;
}
