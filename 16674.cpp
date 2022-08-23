#include <iostream>
using namespace std;

int main() {
    int N, check[10] = {0};
    for (cin >> N; N > 0; N /= 10) {
        ++check[N % 10];
    }
    if (check[3] || check[4] || check[5] || check[6] || check[7] || check[9]) {
        cout << 0;
    } else if (!check[0] || !check[1] || !check[2] || !check[8]) {
        cout << 1;
    } else if (check[0] != check[1] || check[1] != check[2] ||
               check[2] != check[8]) {
        cout << 2;
    } else {
        cout << 8;
    }
    cout << '\n';
    return 0;
}
