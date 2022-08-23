#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        cout << "String #" << i + 1 << '\n';
        for (auto const &x : str) {
            cout << (x == 'Z' ? 'A' : char(x + 1));
        }
        cout << "\n\n";
    }
    return 0;
}
