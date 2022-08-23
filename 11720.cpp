#include <iostream>
#include <limits>
using namespace std;

int main() {
    int n, in, sum = 0;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (; n > 0; --n) {
        in = getc(stdin) - '0';
        sum += in;
    }
    cout << sum;
    return 0;
}
