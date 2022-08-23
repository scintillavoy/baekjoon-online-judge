#include <iostream>
using namespace std;

int main() {
    int X;
    cin.unsetf(ios::oct);
    cin.unsetf(ios::dec);
    cin.unsetf(ios::hex);
    cin >> X;
    cout << X;
    return 0;
}
