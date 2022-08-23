#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= int(sqrt(n)); ++i) {
        if (n % i == 0) {
            sum = sum + i + n / i;
        }
    }
    if (int(sqrt(n)) * int(sqrt(n)) == n) {
        sum -= int(sqrt(n));
    }
    cout << sum * 5 - 24;
    return 0;
}
