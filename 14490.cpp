#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int main() {
    int n, m;
    string input;
    getline(cin, input, ':');
    n = stoi(input);
    getline(cin, input);
    m = stoi(input);
    cout << n / gcd(n, m) << ':' << m / gcd(n, m);
    return 0;
}
