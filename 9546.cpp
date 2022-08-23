#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int k;
        cin >> k;
        int numOfPassenger = 0;
        for (int j = 0; j < k; ++j) {
            numOfPassenger = 2 * numOfPassenger + 1;
        }
        cout << numOfPassenger << '\n';
    }
    return 0;
}
