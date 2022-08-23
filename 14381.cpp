#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int N, check[10] = {0};
        scanf("%d", &N);
        printf("Case #%d: ", i);
        if (!N) {
            printf("INSOMNIA");
        } else {
            int answer = 0;
            for (int j = 0; j < 10;) {
                answer += N;
                for (int k = answer; k > 0; k /= 10) {
                    if (!check[k % 10]) {
                        ++check[k % 10];
                        ++j;
                    }
                }
            }
            printf("%d", answer);
        }
        printf("\n");
    }
    return 0;
}
