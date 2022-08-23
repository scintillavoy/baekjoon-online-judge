#include <iostream>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    --K;
    int elapsedTime = 0;
    while (N--) {
        int T;
        char Z;
        cin >> T >> Z;
        elapsedTime += T;
        if (elapsedTime > 210) {
            break;
        }
        if (Z == 'T') {
            K = (K + 1) % 8;
        }
    }
    cout << K + 1;
    return 0;
}
