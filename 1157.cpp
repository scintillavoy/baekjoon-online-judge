#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
    string input;
    cin >> input;

    int cnt[26] = {0, };
    for (auto const &x : input) {
        ++cnt[toupper(x) - 'A'];
    }

    int max = *max_element(cnt, cnt + 26);
    int index = -1;
    for (int i = 0; i < sizeof(cnt) / sizeof(int); ++i) {
        if (cnt[i] == max) {
            if (index == -1) {
                index = i;
            } else {
                index = -1;
                break;
            }
        }
    }
    
    cout << (char) (index == -1 ? '?' : index + 'A');
    return 0;
}
