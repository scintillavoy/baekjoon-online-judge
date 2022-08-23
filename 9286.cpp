#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int m;
        scanf("%d", &m);
        printf("Case %d:\n", i);
        while (m--) {
            int grade;
            scanf("%d", &grade);
            if (grade < 6) {
                printf("%d\n", grade + 1);
            }
        }
    }
    return 0;
}
