#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;
    V -= A;
    if (V <= 0) {
        cout << 1;
    } else {
        cout << 1 + int(ceil((double) V / (A - B)));
    }
    return 0;
}
