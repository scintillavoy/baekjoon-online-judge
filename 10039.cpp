#include <iostream>
using namespace std;

int main() {
    int input, sum = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> input;
        sum += input > 40 ? input : 40;
    }
    cout << sum / 5;
    return 0;
}
