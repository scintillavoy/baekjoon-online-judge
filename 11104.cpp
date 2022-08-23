#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        cout << stoi(str, nullptr, 2) << '\n';
    }
    return 0;
}
