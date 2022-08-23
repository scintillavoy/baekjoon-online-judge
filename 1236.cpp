#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    getc(stdin);
    vector<bool> row(N), col(M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (getc(stdin) == 'X') {
                row[i] = true;
                col[j] = true;
            }
        }
        getc(stdin);
    }
    printf("%d\n", max(count(row.begin(), row.end(), false),
                        count(col.begin(), col.end(), false)));
    return 0;
}
