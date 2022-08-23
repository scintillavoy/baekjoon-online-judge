#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 0, i, j;
    for (i = 1, j = 1; i * 10 <= N; i *= 10, ++j) {
        cnt += 9 * i * j;
    }
    for (; i <= N; ++i) {
        cnt += j;
    }
    cout << cnt;
    return 0;
}
