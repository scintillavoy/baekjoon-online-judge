#include <iostream>
#include <string>
using namespace std;

bool isAcceptable(const string &pwd) {
    bool vowel = false;
    // 1 is vowel, 2 is consonant
    char prev = 0, curr_type = 0, prev_type = 0, prev2_type = 0;
    for (auto const &curr : pwd) {
        switch (curr) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowel = true;
                curr_type = 1;
                break;
            default:
                curr_type = 2;
                break;
        }
        if ((curr_type == prev_type && prev_type == prev2_type) || 
            (curr == prev && curr != 'e' && curr != 'o')) {
            return false;
        }
        prev2_type = prev_type;
        prev_type = curr_type;
        prev = curr;
    }
    if (!vowel) {
        return false;
    }
    return true;
}

int main() {
    string pwd;
    while (true) {
        cin >> pwd;
        if (pwd == "end") {
            break;
        }
        cout << '<' << pwd << "> is"
             << (isAcceptable(pwd) ? " " : " not ") << "acceptable.\n";
    }
    return 0;
}
