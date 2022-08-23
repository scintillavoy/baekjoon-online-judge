#include <iostream>
using namespace std;

int main() {
    int A, B, C, product;
    int cnt[10] = {0, };
    cin >> A >> B >> C;
    product = A * B * C;
    do {
        ++cnt[product % 10];
    } while (product /= 10);
    for (auto const &x : cnt) {
        cout << x << '\n';
    }
    return 0;
}
