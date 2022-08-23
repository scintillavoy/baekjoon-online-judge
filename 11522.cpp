#include <iostream>
using namespace std;

int main() {
    int P;
    cin >> P;
    while (P--) {
        int K, N;
        cin >> K >> N;
        cout << K << ' ' << N*(N+1)/2 << ' ' << N*N << ' ' << N*(N+1) << '\n';
    }
    return 0;
}
