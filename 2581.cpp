#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= (int) sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int M, N;
    cin >> M >> N;
    int prime_min = 0, prime_sum = 0;
    for (int i = N; i >= M; --i) {
        if (isPrime(i)) {
            prime_sum += i;
            prime_min = i;
        }
    }
    if (prime_sum == 0) {
        cout << -1;
    } else {
        cout << prime_sum << '\n' << prime_min;
    }
    return 0;
}
