#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (!n) {
            break;
        }
        vector<int> income(n);
        double average = 0;
        for (auto &x : income) {
            scanf("%d", &x);
            average += x;
        }
        average /= n;
        int cnt = 0;
        for (auto const &x : income) {
            if (x <= average) {
                ++cnt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
