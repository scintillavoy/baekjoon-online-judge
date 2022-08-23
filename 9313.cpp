#include <iostream>
using namespace std;

int main() {
    unsigned int num;
    while (cin >> num) {
        if (num == -1) {
            break;
        }
        unsigned int num2 = 0;
        for (int i = 0; i < 32; ++i) {
            num2 = num2 * 2 + ((num >> i) & 1);
        }
        cout << num2 << '\n';
    }
    return 0;
}
