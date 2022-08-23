#include <iostream>
using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    int answer = N;
    while (k--) {
        N *= 10;
        answer += N;
    }
    cout << answer;
    return 0;
}
