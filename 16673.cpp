#include <iostream>
using namespace std;

int main() {
    int C, K, P;
    cin >> C >> K >> P;
    cout << C*(C+1)/2*K + C*(C+1)*(2*C+1)/6*P << '\n';
    return 0;   
}
