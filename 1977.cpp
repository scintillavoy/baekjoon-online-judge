#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    int sum = 0, minNum = int(ceil(sqrt(M))) * int(ceil(sqrt(M)));
    for (int i = int(ceil(sqrt(M))); i * i <= N; ++i) {
        sum += i * i;
    }
    if (sum == 0) {
        cout << -1;
    } else {
        cout << sum << '\n';
        cout << minNum;
    }
    return 0;
}
