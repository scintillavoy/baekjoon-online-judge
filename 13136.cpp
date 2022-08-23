#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int R, C, N;
    cin >> R >> C >> N;
    cout << (long long) (ceil((double) R/N)) * (long long) ceil((double) C/N);
    return 0;
}
