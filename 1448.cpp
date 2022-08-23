#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> vec(N);
    for (auto &x : vec) {
        scanf("%d", &x);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    for (int i = 0; i < vec.size() - 2; ++i) {
        if (vec[i] < vec[i+1] + vec[i+2]) {
            printf("%d\n", vec[i] + vec[i+1] + vec[i+2]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
