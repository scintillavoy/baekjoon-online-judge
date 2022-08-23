#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    while (true) {
        string num;
        cin >> num;
        if (num == "0") {
            break;
        }

        int sum = 0;
        for (int i = num.size() - 1; i >= 0; --i) {
            int add = num[i] - '0';
            for (int j = 2; j <= num.size() - i; ++j) {
                add *= j;
            }
            sum += add;
        }
        cout << sum << '\n';
    }
    return 0;
}
