#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        multiset<int> Q;
        int k;
        cin >> k;
        while (k--) {
            char c;
            int n;
            cin >> c >> n;
            if (c == 'I') {
                Q.insert(n);
            } else if (c == 'D') {
                if (!Q.empty()) {
                    if (n == -1) {
                        Q.erase(Q.begin());
                    } else if (n == 1) {
                        Q.erase(--Q.end());
                    }
                }
            }
        }
        if (Q.empty()) {
            cout << "EMPTY";
        } else {
            cout << *Q.crbegin() << ' ' << *Q.cbegin();
        }
        cout << '\n';
    }
    return 0;
}
