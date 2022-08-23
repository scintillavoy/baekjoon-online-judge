#include <cstdio>
#include <cmath>
using namespace std;

#define PI 3.141592653589793

int main() {
    int x, y;
    while (~scanf("%d %d", &x, &y)) {
        if (!x && !y) {
            break;
        }
        printf("%d\n", lround(atan2(y, x) * 180 / PI));
    }
    return 0;
}
