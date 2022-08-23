#include <iostream>
#include <utility>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;
    if (A > B) {
        swap(A, B);
    }
    cout << B * (B + 1) / 2 - (A - 1) * A / 2;
    return 0;
}
