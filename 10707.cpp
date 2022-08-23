#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, P;
    cin >> A >> B >> C >> D >> P;
    int priceX = A * P;
    int priceY = B + (P - C > 0 ? P - C : 0) * D;
    cout << (priceX < priceY ? priceX : priceY);
    return 0;
}
