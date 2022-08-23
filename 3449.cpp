#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string a, b;
        cin >> a >> b;
        int hammingDist = 0;
        for (int j = 0; j < a.size(); ++j) {
            if (a[j] != b[j]) {
                ++hammingDist;
            }
        }
        cout << "Hamming distance is " << hammingDist << ".\n";
    }
    return 0;
}
