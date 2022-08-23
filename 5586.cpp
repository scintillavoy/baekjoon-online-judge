#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt_JOI = 0, cnt_IOI = 0;
    for (auto it = str.cbegin() + 1; it < str.cend(); ++it) {
        if (*it == 'O' && *(it+1) == 'I') {
            if (*(it-1) == 'J') {
                ++cnt_JOI;
            } else if (*(it-1) == 'I') {
                ++cnt_IOI;
            }
        }
    }
    cout << cnt_JOI << '\n' << cnt_IOI;
    return 0;
}
