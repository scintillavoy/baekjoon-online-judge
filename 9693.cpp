#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    for (int i = 1; cin >> N; ++i) {
        if (!N) {
            break;
        }
        int two = 0, five = 0;
        for (int j = 2; j <= N; ++j) {
            int num = j;
            while (num % 2 == 0) {
                ++two;
                num /= 2;
            }
            while (num % 5 == 0) {
                ++five;
                num /= 5;
            }
        }
        cout << "Case #" << i << ": " << min(two, five) << '\n';
    }
    return 0;
}
