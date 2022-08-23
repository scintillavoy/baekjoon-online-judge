#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string str;
        cin >> str;
        cout << str[0] - '0' + str[2] - '0' << '\n';
    }
    return 0;
}
