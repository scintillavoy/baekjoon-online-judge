#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int cnt[26] = {0, };
    for (auto const &x : S) {
        ++cnt[x-'a'];
    }
    for (auto const &x : cnt) {
        cout << x << ' ';
    }
    return 0;
}
