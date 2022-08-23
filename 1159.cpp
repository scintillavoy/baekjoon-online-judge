#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, arr[26] = {0};
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        ++arr[str[0] - 'a'];
    }
    bool withdraw = true;
    for (int i = 0; i < 26; ++i) {
        if (arr[i] >= 5) {
            cout << char(i + 'a');
            withdraw = false;
        }
    }
    if (withdraw) {
        cout << "PREDAJA";
    }
    return 0;
}
