#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        N = (N + 1) / 2;
        printf("%d\n", N * N);
    }
    return 0;
}
