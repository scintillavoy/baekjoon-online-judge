#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int arr[99] = {0};
    for (int i = 0; i < 3; ++i) {
        int a, b;
        cin >> a >> b;
        for (int j = a - 1; j < b - 1; ++j) {
            ++arr[j];
        }
    }
    int price = 0;
    for (auto const &x : arr) {
        switch (x) {
            case 1:
                price += A;
                break;
            case 2:
                price += 2 * B;
                break;
            case 3:
                price += 3 * C;
                break;
        }
    }
    cout << price;
    return 0;
}
