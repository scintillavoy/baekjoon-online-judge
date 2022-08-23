#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double answer = 0, product = 1;
    for (int i = 0; i < N; ++i) {
        double val;
        cin >> val;
        product *= val;
        if (answer < product) {
            answer = product;
        }
        if (product < 1) {
            product = 1;
        }
    }
    cout.precision(3);
    cout << fixed << floor(answer * pow(10, 3) + 0.5) / pow(10, 3);
    return 0;
}
