#include <iostream>
using namespace std;

int main() {
    int N, N_new, cnt = 0;
    cin >> N;
    N_new = N;
    do {
        ++cnt;
        N_new = 10 * (N_new % 10) + (N_new / 10 + N_new % 10) % 10;
    } while (N_new != N);
    cout << cnt;
    return 0;
}
