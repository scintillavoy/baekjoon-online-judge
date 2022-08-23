#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        vector<int> A(N), B(M);
        for (auto &x : A) {
            scanf("%d", &x);
        }
        for (auto &x : B) {
            scanf("%d", &x);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int cnt = 0;
        for (auto const &x : A) {
            for (auto const &y : B) {
                if (x > y) {
                    ++cnt;
                } else {
                    break;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
