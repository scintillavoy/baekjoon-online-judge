#include <iostream>
using namespace std;

int main() {
    int sum;
    cin >> sum;
    for (int i = 0; i < 9; ++i) {
        int price;
        cin >> price;
        sum -= price;
    }
    cout << sum;
    return 0;
}
