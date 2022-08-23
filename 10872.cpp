#include <iostream>
using namespace std;

int main() {
    int N, factorial = 1;
    cin >> N;
    for (int i = 2; i <= N; ++i) {
        factorial *= i;
    }
    cout << factorial;
    return 0;
}
