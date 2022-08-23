#include <iostream>
using namespace std;

int main() {
    int N, F;
    cin >> N >> F;
    N = N / 100 * 100;
    while (N % F != 0) {
        ++N;
    }
    cout << N / 10 % 10 << N % 10;
    return 0;
}
