#include <iostream>
using namespace std;

int main() {
    int y[6] = {1, 1, 2, 2, 2, 8};
    int x[6] = {0, };
    for (auto &elem : x) {
        cin >> elem;
    }
    for (int i = 0; i < 6; ++i) {
        cout << y[i] - x[i] << ' ';
    }
    return 0;
}
