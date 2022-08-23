#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, C;
        cin >> N >> C;
        cout << (N + C - 1) / C << '\n';
    }
    return 0;
}
