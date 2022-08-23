#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int arr[5];
        for (auto &x : arr) {
            cin >> x;
        }
        sort(arr, arr + 5);
        if (arr[3] - arr[1] >= 4) {
            cout << "KIN";
        } else {
            cout << arr[1] + arr[2] + arr[3];
        }
        cout << '\n';
    }
    return 0;
}
