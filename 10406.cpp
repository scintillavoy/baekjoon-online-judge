#include <cstdio>
using namespace std;

int main() {
    int W, N, P;
    scanf("%d %d %d", &W, &N, &P);
    int cnt = 0;
    while (P--) {
        int H;
        scanf("%d", &H);
        if (W <= H && H <= N) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
