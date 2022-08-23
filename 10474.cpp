#include <iostream>
using namespace std;

int main() {
    while (true) {
        int num, den;
        cin >> num >> den;
        if (!num && !den) {
            break;
        }
        cout << num / den << ' ' << num % den << " / " << den << '\n';
    }
    return 0;
}
