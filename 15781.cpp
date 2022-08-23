#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int helmet = 0, vest = 0;
    while (N--) {
        int defense;
        cin >> defense;
        if (helmet < defense) {
            helmet = defense;
        }
    }
    while (M--) {
        int defense;
        cin >> defense;
        if (vest < defense) {
            vest = defense;
        }
    }
    cout << helmet + vest;
    return 0;
}
