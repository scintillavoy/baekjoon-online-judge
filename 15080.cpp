#include <cstdio>
using namespace std;

int main() {
    int h, m, s, h1, m1, s1, h2, m2, s2;
    scanf("%d : %d : %d", &h1, &m1, &s1);
    scanf("%d : %d : %d", &h2, &m2, &s2);
    s = s2 - s1;
    m = m2 - m1;
    h = h2 - h1;
    if (s < 0) {
        --m;
        s += 60;
    }
    if (m < 0) {
        --h;
        m += 60;
    }
    if (h < 0) {
        h += 24;
    }
    printf("%d", h * 3600 + m * 60 + s);
    return 0;
}
