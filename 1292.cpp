#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int sum = 0, num = 1, cnt = 0;
    for (int i = 1; i < A; ++i) {
        if (cnt == num) {
            ++num;
            cnt = 0;
        }
        ++cnt;
    }
    for (int i = A; i <= B; ++i) {
        if (cnt == num) {
            ++num;
            cnt = 0;
        }
        ++cnt;
        sum += num;
    }
    cout << sum;
    return 0;
}
