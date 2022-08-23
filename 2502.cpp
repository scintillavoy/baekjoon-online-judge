#include <iostream>
using namespace std;

int main() {
    int D, K;
    cin >> D >> K;
    int curr = 2, prev = 1, prev2 = 1;
    for (int i = 3; i < D; ++i) {
        prev2 = prev;
        prev = curr;
        curr = prev + prev2;
    }
    for (int A = 1; ; ++A) {
        for (int B = 1; ; ++B) {
            if (prev2 * A + prev * B > K) {
                break;
            } else if (prev2 * A + prev * B == K) {
                cout << A << '\n' << B;
                return 0;
            }
        }
    }
}
