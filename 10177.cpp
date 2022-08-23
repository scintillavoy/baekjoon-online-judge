#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int m;
        scanf("%d", &m);
        vector<vector<int>> vec(m, vector<int>(m));
        for (auto &row : vec) {
            for (auto &x : row) {
                scanf("%d", &x);
            }
        }

        bool isMagicSquare = true;
        int val = 0;
        for (int i = 0; i < m; ++i) {
            val += vec[i][i];
        }

        int val2 = 0;
        for (int i = 0; i < m; ++i) {
            val2 += vec[i][m-1-i];
        }
        if (val != val2) {
            printf("Not a magic square\n");
            continue;
        }

        for (int i = 0; i < m; ++i) {
            val2 = 0;
            for (int j = 0; j < m; ++j) {
                val2 += vec[i][j];
            }
            if (val != val2) {
                printf("Not a magic square\n");
                continue;
            }
        }

        for (int i = 0; i < m; ++i) {
            val2 = 0;
            for (int j = 0; j < m; ++j) {
                val2 += vec[j][i];
            }
            if (val != val2) {
                printf("Not a magic square\n");
                continue;
            }
        }

        printf("Magic square of size %d\n", m);
    }
    return 0;
}
