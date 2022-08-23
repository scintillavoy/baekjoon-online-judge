#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        long long X;
        cin >> X;
        long long sqrtX = (long long) sqrt(X);
        cout << (sqrtX * sqrtX == X ? 1 : 0) << ' ';
    }
    return 0;
}
