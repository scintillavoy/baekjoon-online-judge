#include <iostream>
using namespace std;

int main() {
    int K, D1, D2;
    cin >> K >> D1 >> D2;
    double diff = (double)(D1 - D2) / 2;
    cout << K * K - diff * diff << '\n';
    return 0;
}
