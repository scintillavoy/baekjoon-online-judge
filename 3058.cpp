#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int sum = 0, even_min = 100;
        for (int j = 0; j < 7; ++j) {
            int num;
            cin >> num;
            if (num % 2 == 0) {
                sum += num;
                if (num < even_min) {
                    even_min = num;
                }
            }
        }
        cout << sum << ' ' << even_min << '\n';
    }
    return 0;
}
