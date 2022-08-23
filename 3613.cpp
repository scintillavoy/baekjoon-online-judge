#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string in, out;
    getline(cin, in);
    bool isValid = true;
    if (isupper(in[0]) || in[0] == '_') {
        isValid = false;
    } else {
        bool isJava = false, isCpp = false;
        for (int i = 0; i < in.size() && !(isJava && isCpp); ++i) {
            if (isupper(in[i])) {
                isJava = true;
                out.push_back('_');
                out.push_back(tolower(in[i]));
            } else if (in[i] == '_') {
                isCpp = true;
                ++i;
                if (!isalpha(in[i]) || isupper(in[i])) {
                    isValid = false;
                    break;
                } else {
                    out.push_back(toupper(in[i]));
                }
            } else if (isalpha(in[i])) {
                out.push_back(in[i]);
            } else {
                isValid = false;
                break;
            }
        }
        if (isJava && isCpp) {
            isValid = false;
        }
    }
    cout << (isValid ? out : "Error!");
    return 0;
}
