#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    while (true) {
        getline(cin, input);
        if (input == "END") {
            break;
        }
        for (auto it = input.crbegin(); it != input.crend(); ++it) {
            cout << *it;
        }
        cout << '\n';
    }
    return 0;
}
