#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int C, K;
    cin >> C >> K;
    cout << int(floor(C / pow(10, K) + 0.5) * pow(10, K));
    return 0;
}
