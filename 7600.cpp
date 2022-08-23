#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    while (true) {
        int arr[26] = {0};
        string str;
        getline(cin, str);
        if (str == "#") {
            break;
        }
        for (auto const &x : str) {
            if (isupper(x)) {
                ++arr[x-'A'];
            } else if (islower(x)) {
                ++arr[x-'a'];
            }
        }
        int cnt = 0;
        for (auto const &x : arr) {
            if (x) {
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
