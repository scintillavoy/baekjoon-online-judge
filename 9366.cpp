#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int arr[3];
        for (auto &x : arr) {
            cin >> x;
        }
        sort(arr, arr + 3);
        cout << "Case #" << i << ": ";
        if (arr[0] + arr[1] <= arr[2]) {
            cout << "invalid!";
        } else if (arr[0] == arr[2]) {
            cout << "equilateral";
        } else if (arr[0] == arr[1] || arr[1] == arr[2]) {
            cout << "isosceles";
        } else {
            cout << "scalene";
        }
        cout << '\n';
    }
    return 0;
}
