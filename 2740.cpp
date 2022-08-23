#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int>> A(N, vector<int>(M));
    for (auto &row : A) {
        for (auto &x : row) {
            scanf("%d", &x);
        }
    }
    int K;
    scanf("%d %d", &M, &K);
    vector<vector<int>> B(M, vector<int>(K));
    for (auto &row : B) {
        for (auto &x : row) {
            scanf("%d", &x);
        }
    }
    
    vector<vector<int>> C(N, vector<int>(K));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            for (int k = 0; k < M; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (auto const &row : C) {
        for (auto const &x : row) {
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}
