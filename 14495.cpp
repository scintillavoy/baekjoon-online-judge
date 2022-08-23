#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long arr[4] = {1, 1, 1, 2};
    while (--n) {
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = arr[3];
        arr[3] = arr[0] + arr[2];
    }
    cout << arr[0];
    return 0;
}
