#include <iostream>
#include <string>
using namespace std;

int main() {
    string L, R;
    cin >> L >> R;
    if (L.size() != R.size()) {
        cout << 0;
    } else {
        int numOfEights = 0;
        for (int i = 0; i < L.size(); ++i) {
            if (L[i] != R[i]) {
                break;
            }
            if (L[i] == '8') {
                ++numOfEights;   
            }
        }
        cout << numOfEights;
    }
    return 0;
}
