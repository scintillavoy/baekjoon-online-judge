#include <iostream>
#include <string>
using namespace std;

int main() {
    int left, right;
    string op;
    for (int i = 1; ; ++i) {
        cin >> left >> op >> right;
        if (op == "E") {
            break;
        }
        cout << "Case " << i << ": ";
        if (op == ">") {
            cout << boolalpha << (left > right);
        } else if (op == ">=") {
            cout << boolalpha << (left >= right);
        } else if (op == "<") {
            cout << boolalpha << (left < right);
        } else if (op == "<=") {
            cout << boolalpha << (left <= right);
        } else if (op == "==") {
            cout << boolalpha << (left == right);
        } else if (op == "!=") {
            cout << boolalpha << (left != right);
        }
        cout << '\n';
    }
    return 0;
}
