#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<pair<int, int>> vec(N);
    for (auto &x : vec) {
        scanf("%d %d", &x.first, &x.second);
    }
    sort(vec.begin(), vec.end(),
        [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second < b.second;
            }
    });
    int minPrice = 10001, cnt = 0;
    for (auto const &x : vec) {
        if (minPrice > x.second) {
            minPrice = x.second;
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
