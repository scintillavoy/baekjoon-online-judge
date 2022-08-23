#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    int cnt = 0;
    for (int i = 0; i < 5; ++i) {
        int answer;
        scanf("%d", &answer);
        if (answer == T) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
