#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int num = 1, cnt = 1;
    if (N % 2 == 0 || N % 5 == 0) {
        cout << -1;
    } else {
        while (num % N) {
            num = (num * 10 + 1) % N;
            ++cnt;
        }
        cout << cnt;
    }
    return 0;
}
