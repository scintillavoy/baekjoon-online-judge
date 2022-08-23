#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int C, W, L, P;
    while (~scanf("%d %d %d %d", &C, &W, &L, &P)) {
        if (!C && !W && !L && !P) {
            break;
        }
        printf("%d\n", int(pow(C, W * L * P)));
    }
    return 0;
}
