#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt = 0;
    for (int i = 1; i < str.size(); ++i) {
        if (str[i-1] != str[i]) {
            ++cnt;
        }
    }
    cout << int(ceil((double) cnt / 2));
    return 0;
}
