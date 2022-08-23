#include <cstdio>
using namespace std;

int main() {
    int S[8];
    for (auto &x : S) {
        scanf("%d", &x);
    }
    int maxVal = 0;
    for (int i = 0; i < 8; ++i) {
        int val = 0;
        for (int j = i; j < i + 4; ++j) {
            val += S[j % 8];
        }
        if (maxVal < val) {
            maxVal = val;
        }
    }
    printf("%d\n", maxVal);
    return 0;
}
