#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
    } else {
        int curr = 2, next = 3, next2 = 5;
        while (--n > 1) {
            curr = next % 10;
            next = next2;
            next2 = curr + next;
        }
        cout << curr;
    }
    return 0;
}
