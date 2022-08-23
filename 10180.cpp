#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, D;
        scanf("%d %d", &N, &D);
        int cnt = 0;
        while (N--) {
            int v, f, c;
            scanf("%d %d %d", &v, &f, &c);
            if ((double) D / v * c <= f) {
                ++cnt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
