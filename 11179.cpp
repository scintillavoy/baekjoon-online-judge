#include <iostream>
using namespace std;

int main() {
    int N, N_reversed = 0;
    cin >> N;
    while (N > 0) {
        N_reversed *= 2;
        N_reversed += N % 2;
        N /= 2;
    }
    cout << N_reversed;
    return 0;
}
