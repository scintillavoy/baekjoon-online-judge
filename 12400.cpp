#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    string rule("yhesocvxduiglbkrztnwjpfmaq");
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 1; i <= T; ++i) {
        string G;
        getline(cin, G);
        cout << "Case #" << i << ": ";
        for (auto const &x : G) {
            if (x == ' ') {
                cout << ' ';
            } else {
                cout << rule[x - 'a'];
            }
        }
        cout << '\n';
    }
    return 0;
}
