#include <cstdio>
#include <vector>
#include <algorithm>
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
    int score = 0, multiplier = vec[0];
    for (int i = 1; i < vec.size(); ++i) {
        score += vec[i] * multiplier;
        multiplier += vec[i];
    }
    printf("%d\n", score);
    return 0;
}
