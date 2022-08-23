#include <iostream>
using namespace std;

int main() {
    int arr[6] = {500, 100, 50, 10, 5, 1};
    int money, cnt = 0;
    cin >> money;
    money = 1000 - money;
    for (auto const &x : arr) {
        cnt += money / x;
        money %= x;
    }
    cout << cnt;
    return 0;
}
