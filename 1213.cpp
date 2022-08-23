#include <iostream>
#include <string>
using namespace std;

int main() {
    int arr[26] = {0};
    string name;
    cin >> name;
    for (auto const &x : name) {
        ++arr[x - 'A'];
    }
    int check = -1;
    for (int i = 0; i < 26; ++i) {
        if (arr[i] % 2) {
            if (check != -1) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            check = i;
        }
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < arr[i] / 2; ++j) {
            cout << char('A' + i);
        }
    }
    if (check != -1) {
        cout << char('A' + check);
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < arr[26 - i - 1] / 2; ++j) {
            cout << char('A' + 26 - i - 1);
        }
    }
    return 0;
}
