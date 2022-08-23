#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    long long result = 1;
    for (int i = 0; i < N; ++i) {
        long long ai;
        cin >> ai;
        result = (result * (ai % M)) % M;
    }
    cout << result;
    return 0;
}
