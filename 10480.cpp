#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        cout << num << " is " << (num % 2 ? "odd" : "even") << '\n';
    }
    return 0;
}
