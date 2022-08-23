#include <iostream>
using namespace std;

int main() {
    int x_arr[3], y_arr[3];
    for (int i = 0; i < 3; ++i) {
        cin >> x_arr[i] >> y_arr[i];
    }
    if (x_arr[0] == x_arr[1]) {
        cout << x_arr[2];
    } else if (x_arr[0] == x_arr[2]) {
        cout << x_arr[1];
    } else {
        cout << x_arr[0];
    }
    cout << ' ';
    if (y_arr[0] == y_arr[1]) {
        cout << y_arr[2];
    } else if (y_arr[0] == y_arr[2]) {
        cout << y_arr[1];
    } else {
        cout << y_arr[0];
    }
    return 0;
}
