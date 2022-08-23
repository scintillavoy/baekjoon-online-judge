#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N, K, B;
    scanf("%d %d %d", &N, &K, &B);
    vector<int> vec(N);
    for (auto &x : vec) {
        scanf("%d", &x);
    }
    int sum = 0;
    for (int i = 0; i < K; ++i) {
        sum += vec[(B + i - 1) % N];
    }
    printf("%d\n", sum);
    return 0;
}
