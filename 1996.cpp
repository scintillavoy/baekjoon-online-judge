#include <cstdio>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<vector<int>> vec(N+2, vector<int>(N+2));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            char c;
            scanf(" %c", &c);
            if (c != '.') {
                vec[i-1][j-1] += c - '0';
                vec[i-1][j] += c - '0';
                vec[i-1][j+1] += c - '0';
                vec[i][j-1] += c - '0';
                vec[i][j] = numeric_limits<int>::min();
                vec[i][j+1] += c - '0';
                vec[i+1][j-1] += c - '0';
                vec[i+1][j] += c - '0';
                vec[i+1][j+1] += c - '0';
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (vec[i][j] < 0) {
                printf("*");
            } else if (vec[i][j] >= 10) {
                printf("M");
            } else {
                printf("%d", vec[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
