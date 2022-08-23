#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; ++i) {
        string name;
        getline(cin, name);
        int cntG = 0, cntB = 0;
        for (auto const &x : name) {
            switch (x) {
                case 'G':
                case 'g':
                    ++cntG;
                    break;
                case 'B':
                case 'b':
                    ++cntB;
                    break;
            }
        }
        cout << name << " is ";
        if (cntG > cntB) {
            cout << "GOOD";
        } else if (cntG < cntB) {
            cout << "A BADDY";
        } else {
            cout << "NEUTRAL";
        }
        cout << '\n';
    }
    return 0;
}
