#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int sum = 0;
    for (int i = 1, j = 1, k = 1; i <= B; ++i, ++k) {
        if (i >= A) {
            sum += j;
        }
        if (j == k) {
            ++j;
            k = 0;
        }
    }
    cout << sum;
    return 0;
}
