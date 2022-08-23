#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        string str;
        cin >> str;
        if (str == "*") {
            break;
        }
        bool isSurprising = true;
        for (int len = 1; len < str.size(); ++len) {
            int arr[26][26] = {0};
            for (int i = 0; i < str.size() - len; ++i) {
                int j = i + len;
                if (arr[str[i]-'A'][str[j]-'A']) {
                    isSurprising = false;
                } else {
                    ++arr[str[i]-'A'][str[j]-'A'];
                }
            }
        }
        cout << str << " is " << (isSurprising ? "" : "NOT ") << "surprising.\n";
    }
    return 0;
}
