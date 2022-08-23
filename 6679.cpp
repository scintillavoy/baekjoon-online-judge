#include <iostream>
using namespace std;

int main() {
    for (int i = 1000; i <= 9999; ++i) {
        int sum_10 = 0, sum_12 = 0, sum_16 = 0;
        for (int j = i; j > 0; j /= 10) {
            sum_10 += j % 10;
        }
        for (int j = i; j > 0; j /= 12) {
            sum_12 += j % 12;
        }
        for (int j = i; j > 0; j /= 16) {
            sum_16 += j % 16;
        }
        if (sum_10 == sum_12 && sum_12 == sum_16) {
            cout << i << '\n';
        }
    }
    return 0;
}
