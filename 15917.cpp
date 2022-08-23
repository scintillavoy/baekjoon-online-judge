#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int a;
        cin >> a;
        cout << ((a & (-a)) == a ? 1 : 0) << '\n';
    }
    return 0;
}
