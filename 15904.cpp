#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, abbr("UCPC");
    getline(cin, str);
    int idx = 0;
    for (auto const &x : str) {
        if (x == abbr[idx]) {
            if (++idx == 4) {
                break;
            }
        }
    }
    cout << "I " << (idx == 4 ? "love" : "hate") << " UCPC\n";
    return 0;
}
