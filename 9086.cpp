#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    string input;
    for (int i = 0; i < T; ++i) {
        cin >> input;
        cout << input.front() << input.back() << '\n';
    }
    return 0;
}
