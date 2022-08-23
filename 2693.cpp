#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int arr[3] = {0};
        for (int j = 0; j < 10; ++j) {
            int num;
            cin >> num;
            if (num > arr[0]) {
                arr[2] = arr[1];
                arr[1] = arr[0];
                arr[0] = num;
            } else if (num > arr[1]) {
                arr[2] = arr[1];
                arr[1] = num;
            } else if (num > arr[2]) {
                arr[2] = num;
            }
        }
        cout << arr[2] << '\n';
    }
    return 0;
}
