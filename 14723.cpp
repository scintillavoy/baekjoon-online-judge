#include <cstdio>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int a = 1, b = 1;
    while (--N) {
        if (a == 1) {
            a = b + 1;
            b = 1;
        } else {
            --a;
            ++b;
        }
    }
    printf("%d %d", a, b);
    return 0;
}
