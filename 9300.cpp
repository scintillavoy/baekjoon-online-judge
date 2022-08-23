#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141592653589793

int main() {
    int T;
    cin >> T;
    cout << fixed;
    for (int i = 1; i <= T; ++i) {
        double height, angle;
        cin >> height >> angle;
        cout << "Case " << i << ": ";
        cout << abs(height / tan(angle * PI / 180) - height) << '\n';
    }
    return 0;
}
