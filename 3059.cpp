#include <iostream>
#include <cstdio>
#include <limits>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < T; ++i) {
        int arr[26] = {0};
        char c;
        while ((c = getc(stdin)) != '\n') {
            ++arr[c - 'A'];
        }
        int sum = 0;
        for (int j = 0; j < 26; ++j) {
            if (arr[j] == 0) {
                sum += j + 'A';
            }
        }
        cout << sum << '\n';
    }
    return 0;

}