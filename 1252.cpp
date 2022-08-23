#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<81> a, b, sum;
    cin >> a >> b;
    for (int carry = 0, i = 0; i < sum.size(); ++i) {
        sum[i] = a[i] ^ b[i] ^ carry;
        carry = (a[i] & b[i]) | (a[i] & carry) | (b[i] & carry);
    }
    int idx;
    for (idx = sum.size() - 1; idx > 0; --idx) {
        if (sum[idx]) {
            break;
        }
    }
    for (int i = idx; i >= 0; --i) {
        cout << sum[i];
    }
    return 0;
}
