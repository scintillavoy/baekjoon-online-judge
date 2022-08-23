#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[5] = {0}, sum = 0;
    for (auto &x : arr) {
        cin >> x;
        sum += x;
    }
    sort(arr, arr + 5);
    cout << sum / 5 << '\n';
    cout << arr[2];
    return 0;
}
