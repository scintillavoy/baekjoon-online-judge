#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int L, R, A;
    cin >> L >> R >> A;
    if (L > R) {
        swap(L, R);
    }
    cout << L*2 + min(R-L, A)*2 + max(A-(R-L), 0)/2*2 << '\n';
    return 0;
}
