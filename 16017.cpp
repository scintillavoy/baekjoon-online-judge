#include <cstdio>
using namespace std;

int main() {
    int num[4];
    for (auto &x : num) {
        scanf("%d", &x);
    }
    if ((num[0] == 8 || num[0] == 9) &&
        (num[1] == num[2]) &&
        (num[3] == 8 || num[3] == 9)) {
        printf("ignore");
    } else {
        printf("answer");
    }
    printf("\n");
    return 0;
}
