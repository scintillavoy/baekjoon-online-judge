#include <iostream>
#include <bitset>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    bitset<4> check;
    while (K--) {
        int x, y;
        cin >> x >> y;
        check.set((x + y) % 2 + (x % 2) * 2);
    }
    cout << (check.all() ? "YES" : "NO") << '\n';
    return 0;
}
