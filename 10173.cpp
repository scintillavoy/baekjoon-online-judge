#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        string str;
        getline(cin, str);
        if (str == "EOI") {
            break;
        }
        bool flag = false;
        for (auto it = str.cbegin(); it < str.cend() - 3; ++it) {
            if ((*it == 'N' || *it == 'n')
                && (*(it+1) == 'E' || *(it+1) == 'e')
                && (*(it+2) == 'M' || *(it+2) == 'm')
                && (*(it+3) == 'O' || *(it+3) == 'o')) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "Found" : "Missing") << '\n';
    }
    return 0;
}
