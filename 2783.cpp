#include <iostream>
using namespace std;

int main() {
    int X, Y, N;
    cin >> X >> Y >> N;
    double minPrice = (double) X / Y;
    for (int i = 0; i < N; ++i) {
        cin >> X >> Y;
        if ((double) X / Y < minPrice) {
            minPrice = (double) X / Y;
        }
    }
    cout.precision(2);
    cout << fixed << minPrice * 1000;
    return 0;
}
