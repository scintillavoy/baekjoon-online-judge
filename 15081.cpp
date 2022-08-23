#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<string> selected;
    while (n--) {
        int m;
        cin >> m;
        string name;
        while (m--) {
            cin >> name;
            if (!selected.count(name)) {
                selected.insert(name);
                cout << name << ' ';
                break;
            }
        }
        while (m--) {    // discard rest
            cin >> name;
        }
    }
    cout << '\n';
    return 0;
}
