#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (true) {
        int num;
        cin >> num;
        if (num == 0) {
            break;
        }
        cout << num << (num % n == 0 ? " is " : " is NOT ");
        cout << "a multiple of " << n << ".\n";
    }
    return 0;
}
