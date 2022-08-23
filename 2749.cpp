#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    n %= 1500000;
    int prev = 0, curr = 0, next = 1;
    for (long long i = 0; i < n; ++i) {
        prev = curr;
        curr = next % 1000000;
        next = prev + curr;
    }
    cout << curr;
    return 0;
}
