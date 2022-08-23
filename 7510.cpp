#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        unsigned int arr[3];
        for (auto &x : arr) {
            cin >> x;
            x *= x;
        }
        sort(arr, arr + 3);
        cout << "Scenario #" << i << ":\n";
        if (arr[0] + arr[1] == arr[2]) {
            cout << "yes";
        } else {
            cout << "no";
        }
        cout << "\n\n";
    }
    return 0;
}
