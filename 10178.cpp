#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int a, b;
        cin >> a >> b;
        cout << "You get " << a / b << " piece(s) and your dad gets "
             << a % b << " piece(s).\n";
    }
    return 0;
}
