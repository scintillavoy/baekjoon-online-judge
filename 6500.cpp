#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int a0;
    while (cin >> a0) {
        if (!a0) {
            break;
        }
        unordered_set<int> s;
        while (!s.count(a0)) {
            s.insert(a0);
            a0 = a0 * a0 / 100 % 10000;
        }
        cout << s.size() << '\n';
    }
    return 0;
}
