#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int L;
        scanf("%d", &L);
        getc(stdin);
        vector<char> vec(L);
        for (auto &x : vec) {
            x = getc(stdin);
        }
        getc(stdin);
        int cnt = 0;
        for (int j = 0; j < L; ++j) {
            if (vec[j] != getc(stdin)) {
                ++cnt;
            }
        }
        printf("Case %d: %d\n", i, cnt);
    }
    return 0;
}
