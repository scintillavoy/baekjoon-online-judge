#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        bitset<6> h2(h), m2(m), s2(s);
        for (int i = 5; i >= 0; --i) {
            cout << h2[i] << m2[i] << s2[i];
        }
        cout << ' ' << h2 << m2 << s2 << '\n';
    }
    return 0;
}
