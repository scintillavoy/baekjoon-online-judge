#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    bool curr = false, next = false, next2 = false;
    while (N--) {
        bool input;
        cin >> input;
        if (input != curr) {
            ++cnt;
            next = !next;
            next2 = !next2;
        }
        curr = next;
        next = next2;
        next2 = false;
    }
    cout << cnt;
    return 0;
}
