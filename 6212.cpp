#include <iostream>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    int cnt[10] = {0};
    for (int i = M; i <= N; ++i) {
        for (int j = i; j > 0; j /= 10) {
            ++cnt[j % 10];
        }
    }
    for (auto const &x : cnt) {
        cout << x << ' ';
    }
    return 0;
}
