#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    long long A, B;
    scanf("%lld %lld", &A, &B);
    if (A > B) {
        swap(A, B);
    }
    printf("%d\n", (A == B ? 0 : B - A - 1));
    while (++A < B) {
        printf("%lld ", A);
    }
    return 0;
}
