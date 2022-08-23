#include <iostream>
using namespace std;

int main() {
    int curr, next = 1, cnt = 0;
    cin >> curr;
    while (curr >= 10) {
        while (curr > 0) {
            next *= curr % 10;
            curr /= 10;
        }
        curr = next;
        next = 1;
        ++cnt;
    }
    cout << cnt;
    return 0;
}
