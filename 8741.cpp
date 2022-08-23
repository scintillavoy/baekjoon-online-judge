#include <cstdio>
using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        putc('1', stdout);
    }
    for (int i = 0; i < k - 1; ++i) {
        putc('0', stdout);
    }
    return 0;
}
