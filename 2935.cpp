#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string A, B;
    char op;
    cin >> A >> op >> B;
    if (op == '+') {
        string result;
        while (!A.empty() && !B.empty()) {
            result.push_back(A.back() + B.back() - '0');
            A.pop_back();
            B.pop_back();
        }
        while (!A.empty()) {
            result.push_back(A.back());
            A.pop_back();
        }
        while (!B.empty()) {
            result.push_back(B.back());
            B.pop_back();
        }
        reverse(result.begin(), result.end());
        cout << result;
    } else if (op == '*') {
        cout << '1';
        for (int i = 0; i < A.size() + B.size() - 2; ++i) {
            cout << '0';
        }
    }
    return 0;
}
