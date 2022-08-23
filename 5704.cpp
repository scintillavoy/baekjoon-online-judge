#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        if (str == "*") {
            break;
        }
        int arr[26] = {0};
        for (auto const &x : str) {
            if (islower(x)) {
                ++arr[x-'a'];
            }
        }
        bool isPangram = true;
        for (auto const &x : arr) {
            if (x == 0) {
                isPangram = false;
                cout << "N\n";
                break;
            }
        }
        if (isPangram) {
            cout << "Y\n";
        }
    }
    return 0;
}
