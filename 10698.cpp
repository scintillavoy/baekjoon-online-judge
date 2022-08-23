#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int a, b, c;
        char op;
        scanf("%d %c %d = %d", &a, &op, &b, &c);
        printf("Case %d: ", i);
        if (op == '+') {
            printf(a + b == c ? "YES" : "NO");
        } else if (op == '-') {
            printf(a - b == c ? "YES" : "NO");
        }
        printf("\n");
    }
    return 0;
}
