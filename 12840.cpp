#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h, m, s, tc;
    cin >> h >> m >> s >> tc;
    while (tc--) {
        int T, c;
        cin >> T;
        switch (T) {
            case 1:
                cin >> c;
                s += c % 60;
                m += c % 3600 / 60;
                h += c / 3600;
                if (s >= 60) {
                    ++m;
                    s -= 60;
                }
                if (m >= 60) {
                    ++h;
                    m -= 60;
                }
                while (h >= 24) {
                    h -= 24;
                }
                break;
            case 2:
                cin >> c;
                s -= c % 60;
                m -= c % 3600 / 60;
                h -= c / 3600;
                if (s < 0) {
                    --m;
                    s += 60;
                }
                if (m < 0) {
                    --h;
                    m += 60;
                }
                while (h < 0) {
                    h += 24;
                }
                break;
            case 3:
                cout << h << ' ' << m << ' ' << s << '\n';
                break;
        }
    }
    return 0;
}
