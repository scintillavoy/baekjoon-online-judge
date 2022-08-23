#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int n;
        scanf("%d", &n);
        printf("Case %d: %d", i, n - 1);
        int coefficient;
        for (int j = n; j > 0; --j) {
            scanf("%d", &coefficient);
            printf(" %d", coefficient * j);
        }
        scanf("%d", &coefficient);
        printf("\n");
    }
    return 0;
}
