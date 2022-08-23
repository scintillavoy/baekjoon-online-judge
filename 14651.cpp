#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long answer = 0;
    if (N > 1) {
        answer = 2;
    }
    while (--N > 1) {
        answer = answer * 3 % 1000000009;
    }
    cout << answer;
    return 0;
}
