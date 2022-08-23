#include <iostream>
using namespace std;

int main() {
    while (true) {
        int a, b;
        cin >> a >> b;
        if (!a && !b) {
            break;
        }
        cout << (a > b ? "Yes" : "No") << '\n';
    }
    return 0;
}
