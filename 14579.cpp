#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    long long answer = 1;
    for (int i = a; i <= b; ++i) {
        answer = answer * i * (i + 1) / 2 % 14579;
    }
    cout << answer;
    return 0;
}
