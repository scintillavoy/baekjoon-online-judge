#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> vec(N);
    for (auto &x : vec) {
        scanf("%d", &x);
    }
    sort(vec.begin(), vec.end());
    long long dissatisfaction = 0;
    for (int i = 0; i < N; ++i) {
        dissatisfaction += abs(i + 1 - vec[i]);
    }
    printf("%lld\n", dissatisfaction);
    return 0;
}
