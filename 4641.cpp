#include <iostream>
using namespace std;

int main() {
    while (true) {
        int arr[100] = {0};
        while (true) {
            int num;
            cin >> num;
            if (num == -1) {
                return 0;
            } else if (num == 0) {
                break;
            } else {
                ++arr[num];
            }
        }

        int cnt = 0;
        for (int i = 1; i <= 49; ++i) {
            if (arr[i] && arr[i * 2]) {
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
}
