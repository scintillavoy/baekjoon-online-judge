#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int num = 1;
    for (int i = 2; i <= N; ++i) {
        int mul = i;
        while (mul % 10 == 0) {
            mul /= 10;
        }
        num *= mul;
        while (num % 10 == 0) {
            num /= 10;
        }
        num %= 100000;
    }
    cout << num % 10;
    return 0;
}
