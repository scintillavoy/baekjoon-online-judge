#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        vector<pair<int ,int>> vec(N);
        for (auto &x : vec) {
            scanf("%d %d", &x.first, &x.second);
        }
        sort(vec.begin(), vec.end(),
            [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.first < b.first;
        });
        int minRank = N + 1, cnt = 0;
        for (auto const &x : vec) {
            if (minRank > x.second) {
                minRank = x.second;
                ++cnt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
