#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    vector<int> result;
    while (!A.empty() || !B.empty()) {
        int a = 0, b = 0;
        if (!A.empty()) {
            a = A.back() - '0';
            A.pop_back();
        }
        if (!B.empty()) {
            b = B.back() - '0';
            B.pop_back();
        }
        result.push_back(a + b);
    }
    for (auto it = result.crbegin(); it != result.crend(); ++it) {
        cout << *it;
    }
    return 0;
}
