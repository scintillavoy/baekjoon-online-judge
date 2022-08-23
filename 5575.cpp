#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3; ++i) {
        int h, m, s, h1, m1, s1, h2, m2, s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        h = h2 - h1;
        m = m2 - m1;
        s = s2 - s1;
        if (s < 0) {
            --m;
            s += 60;
        }
        if (m < 0) {
            --h;
            m += 60;
        }
        cout << h << ' ' << m << ' ' << s << '\n';
    }
    return 0;
}
