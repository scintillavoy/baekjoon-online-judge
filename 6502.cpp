#include <iostream>
using namespace std;

int main() {
    double r, w, l;
    for (int i = 1; cin >> r; ++i) {
        if (r == 0) {
            break;
        }
        cin >> w >> l;
        cout << "Pizza " << i << " ";
        if (w/2 * w/2 + l/2 * l/2 > r * r) {
            cout << "does not fit";
        } else {
            cout << "fits";
        }
        cout << " on the table.\n";
    }
    return 0;
}
