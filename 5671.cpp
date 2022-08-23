#include <iostream>
using namespace std;

bool check(int i) {
    int arr[10] = {0};
    do {
        if (arr[i % 10] == 0) {
            ++arr[i % 10];
        } else {
            return false;
        }
    } while (i /= 10);
    return true;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        int cnt = 0;
        for (int i = N; i <= M; ++i) {
            if (check(i)) {
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
