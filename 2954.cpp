#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    for (auto it = input.cbegin(); it < input.cend(); ++it) {
        cout << *it;
        switch (*it) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                it += 2;
                break;
        }
    }
    return 0;
}
