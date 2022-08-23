#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long sum = 0;
    for (int i = 1; i < N; ++i) {
        sum += (long long) N * i + i;
    }
    cout << sum;
    return 0;
}
