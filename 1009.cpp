#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int answer = 1;
        while (b--) {
            answer = answer * a % 10;
        }
        cout << (answer ? answer : 10) << '\n';
    }
    return 0;
}
