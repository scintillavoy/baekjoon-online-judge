#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 10; i < N; i *= 10) {
        if (N % i >= i / 2) {
            N += i - N % i;
        } else {
            N -= N % i;
        }
    }
    cout << N;
    return 0;
}
