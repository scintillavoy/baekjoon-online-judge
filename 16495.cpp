#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    long long cnt = 0;
    for (auto const &x : str) {
        cnt = cnt * 26 + x - 'A' + 1;
    }
    cout << cnt << '\n';
    return 0;
}
