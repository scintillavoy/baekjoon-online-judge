#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 1;
    for (int i = 1; i <= N; ++i) {
        cnt += i * 3 + 1;
        cnt %= 45678;
    }
    cout << cnt;
    return 0;
}
