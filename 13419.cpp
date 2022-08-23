#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str, first, second;
        cin >> str;
        if (str.size() % 2) {
            for (int i = 0; i < str.size() * 2; i += 2) {
                first.push_back(str[i % str.size()]);
                second.push_back(str[(i+1) % str.size()]);
            }
        } else {
            for (int i = 0; i < str.size(); i += 2) {
                first.push_back(str[i]);
                second.push_back(str[i+1]);
            }
        }
        cout << first << '\n';
        cout << second << '\n';
    }
    return 0;
}
