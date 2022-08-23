#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int cnt = 0;
    while (A + 1 != B || B + 1 != C) {
        if (B - A > C - B) {
            C = B;
            --B;
        } else {
            A = B;
            ++B;
        }
        ++cnt;
    }
    cout << cnt;
    return 0;
}
