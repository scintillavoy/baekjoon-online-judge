#include <iostream>
using namespace std;

int main() {
    int arr[42] = {0, };
    for (int i = 0; i < 10; ++i) {
        int num;
        cin >> num;
        arr[num % 42] = 1;
    }
    int cnt = 0;
    for (auto const &x : arr) {
        if (x) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
