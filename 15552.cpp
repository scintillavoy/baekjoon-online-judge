#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t, a, b;
    for (cin >> t; t > 0; --t) {
        cin >> a >> b;
        cout << a + b << '\n';
    }
    return 0;
}
