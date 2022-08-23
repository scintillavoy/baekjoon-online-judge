#include <iostream>
using namespace std;

int main() {
    int curr, prev;
    cin >> prev;
    bool flag = true;
    while (cin >> curr) {
        if (prev > curr) {
            flag = false;
        }
        prev = curr;
    }
    cout << (flag ? "Good" : "Bad");
    return 0;
}
