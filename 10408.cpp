#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string S;
    cin >> S;
    int cnt = 0, sum = 0;
    for (auto const &x : S) {
        if (x == '0') {
            sum += 9;
        } else {
            ++cnt;
            sum += x - '0';
        }
    }
    cout.precision(2);
    cout << fixed;
    cout << floor((double) sum / cnt * pow(10, 2) + 0.5) / pow(10, 2) << '\n';
    return 0;
}
