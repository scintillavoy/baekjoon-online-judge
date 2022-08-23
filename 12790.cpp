#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int arr[4];
        for (int j = 0; j < 4; ++j) {
            cin >> arr[j];
        }
        for (int j = 0; j < 4; ++j) {
            int delta;
            cin >> delta;
            arr[j] += delta;
        }
        if (arr[0] < 1) {
            arr[0] = 1;
        }
        if (arr[1] < 1) {
            arr[1] = 1;
        }
        if (arr[2] < 0) {
            arr[2] = 0;
        }
        cout << arr[0] + 5*arr[1] + 2*arr[2] + 2*arr[3] << '\n';
    }
    return 0;
}
