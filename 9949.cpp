#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    char a, b;
    for (int i = 1; cin >> a >> b; ++i) {
        if (a == '#' && b == '#') {
            break;
        }
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Case " << i << '\n';
        while (n--) {
            string sentence;
            getline(cin, sentence);
            for (auto const &x : sentence) {
                cout << ((tolower(x) == a || tolower(x) == b) ? '_' : x);
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}