#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    cout << (int) (-1 + sqrt(4*N - 3)) / 2;
    return 0;
}
