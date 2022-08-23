#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    for (int B = 1; B <= 500; ++B) {
        for (int A = B; A <= 500; ++A) {
            if (A * A - B * B == N) {
                ++cnt;
            }
        }
    }
    cout << cnt;
    return 0;
}
