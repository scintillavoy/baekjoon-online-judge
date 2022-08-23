#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int result = 1;
    for (int i = 0; i < K; ++i) {
        result *= N - i;
        result /= i + 1;
    }
    cout << result;
    return 0;
}
