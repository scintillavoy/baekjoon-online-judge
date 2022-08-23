#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int arr[10] = {0};
        string num;
        cin >> num;
        for (auto const &x : num) {
            ++arr[x - '0'];
        }
        int cnt = 0;
        for (auto const &x : arr) {
            if (x > 0) {
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
