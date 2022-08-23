#include <iostream>
using namespace std;

int main() {
    int num;
    while (cin >> num) {
        if (!num) {
            break;
        }
        while (num >= 10) {
            int temp = 0;
            while (num > 0) {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
        }
        cout << num << '\n';
    }
    return 0;
}
