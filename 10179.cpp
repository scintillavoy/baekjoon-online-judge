#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    cout.precision(2);
    cout << fixed << showpoint;
    for (int i = 0; i < T; ++i) {
        double price;
        cin >> price;
        cout << '$' << floor(price*0.8*pow(10, 2) + 0.5) / pow(10, 2) << '\n';
    }
    return 0;
}
