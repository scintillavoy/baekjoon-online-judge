#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int A, B, N;
    cin >> A >> B >> N;
    int minClick = abs(A - B);
    while (N--) {
        int channel;
        cin >> channel;
        if (minClick > abs(channel - B) + 1) {
            minClick = abs(channel - B) + 1;
        }
    }
    cout << minClick;
    return 0;
}
